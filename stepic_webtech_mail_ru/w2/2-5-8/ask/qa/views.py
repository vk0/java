from django.shortcuts import render, get_object_or_404
from django.http import HttpResponse, HttpResponseRedirect
from django.core.paginator import Paginator, EmptyPage
from django.contrib import auth
from django.views.decorators.http import require_POST
from qa.models import Question, Answer
from qa.forms import AskForm, AnswerForm, SignupForm, LoginForm

def paginate(request, qs):
    try:
        limit = int(request.GET.get('limit', 10))
    except ValueError:
        limit = 10
    if limit > 100:
        limit = 10
    try:
        page = int(request.GET.get('page', 1))
    except ValueError:
        raise Http404
    paginator = Paginator(qs, limit)
    try:
        page = paginator.page(page)
    except EmptyPage:
        page = paginator.page(paginator.num_pages)
    return page
def test(request, *args, **kwargs):
    return HttpResponse('OK')
def new_questions(request):
    qs = Question.objects.new()
    page = paginate(request, qs)
    return render(request, 'list.html', { 'page': page, 'title': 'new questions' })
def popular_questions(request):
    qs = Question.objects.popular()
    page = paginate(request, qs)
    return render(request, 'list.html', { 'page': page, 'title': 'popular questions' })
def one_question(request, id):
    question = get_object_or_404(Question, pk=id)
    qs = question.answer_set.all()
    page = paginate(request, qs)
    form = AnswerForm(initial={'question': question.pk })
    return render(request, 'question.html', { 'question': question, 'page': page, 'form': form })
def ask(request):
    if request.method == 'POST':
        form = AskForm(request.POST)
        if request.user.is_authenticated():
            form._user = request.user
        if form.is_valid():
            q = form.save()
            return HttpResponseRedirect('/question/' + str(q.pk) + '/')
    else:
        form = AskForm()
    return render(request, 'ask.html', { 'form': form })
@require_POST
def answer(request):
    form = AnswerForm(request.POST)
    if request.user.is_authenticated():
        form._user = request.user
    if form.is_valid():
        a = form.save()
        return HttpResponseRedirect('/question/' + str(a.question.pk) + '/')
    else:
        return HttpResponseRedirect('/question/' + str(a.question.pk) + '/?err=1')
def signup(request):
    if request.method == 'POST':
        form = SignupForm(request.POST)
        if form.is_valid():
            user = form.save()
            auth.login(request, user)
            return HttpResponseRedirect('/')
    else:
        form = SignupForm()
    return render(request, 'signup.html', { 'form': form })

def login(request):
    if request.method == 'POST':
        form = LoginForm(request.POST)
        if form.is_valid():
            user = form.load()
            auth.login(request, user)
            return HttpResponseRedirect('/')
    else:
        form = LoginForm()
    return render(request, 'login.html', { 'form': form })