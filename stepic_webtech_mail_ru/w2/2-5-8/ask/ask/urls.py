from django.conf.urls import patterns, include, url
from django.contrib import admin
from qa.views import test, new_questions, popular_questions, one_question, ask, answer, signup, login

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'ask.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
    url(r'^$', new_questions, name='home'),
    url(r'login/$', login, name='login'),
    url(r'signup/$', signup, name='signup'),
    url(r'ask/$', ask, name='ask'),
    url(r'answer/$', answer, name='anwer'),
    url(r'popular/$', popular_questions, name='popular'),
    url(r'new/$', new_questions, name='new'),
    url(r'question/(?P<id>\d+)/$', one_question, name='question'),
    url(r'^admin/', include(admin.site.urls)),
)
