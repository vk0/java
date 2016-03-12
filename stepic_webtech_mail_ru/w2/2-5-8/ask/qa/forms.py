from django import forms
from qa.models import Question, Answer
from django.contrib.auth.models import User
from django.contrib.auth import authenticate

class AskForm(forms.Form):
    title = forms.CharField(max_length=100)
    text = forms.CharField(widget=forms.Textarea)
    def save(self):
        return Question.objects.create(
            title=self.cleaned_data['title'],
            text=self.cleaned_data['text'],
            author=getattr(self, '_user', None),
        )
class AnswerForm(forms.Form):
    text = forms.CharField()
    question = forms.IntegerField()
    def save(self):
        return Answer.objects.create(
            text=self.cleaned_data['text'],
            question_id=self.cleaned_data['question'],
            author=getattr(self, '_user', None),
        )
class SignupForm(forms.Form):
    username = forms.CharField()
    email = forms.EmailField()
    password = forms.CharField(widget=forms.PasswordInput)
    def save(self):
        User.objects.create_user(
            username=self.cleaned_data['username'],
            email=self.cleaned_data['email'],
            password=self.cleaned_data['password'],
        )
        return authenticate(
            username=self.cleaned_data['username'],
            password=self.cleaned_data['password'],
        )
class LoginForm(forms.Form):
    username = forms.CharField()
    password = forms.CharField(widget=forms.PasswordInput)
    def load(self):
        return authenticate(
            username=self.cleaned_data['username'],
            password=self.cleaned_data['password'],
        )