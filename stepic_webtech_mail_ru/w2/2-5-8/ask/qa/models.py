from django.db import models
from django.contrib.auth.models import User
from datetime import datetime

class QuestionManager(models.Manager):
    def new(self):
        return self.order_by('-added_at')
    def popular(self):
        return self.order_by('-rating')

class Question(models.Model):
    title = models.CharField(max_length=100)
    text = models.TextField()
    added_at = models.DateTimeField(default=datetime.now)
    author = models.ForeignKey(User, blank=True, null=True)
    likes = models.ManyToManyField(User, related_name='liked_question_set')
    rating = models.IntegerField(default=0)
    objects = QuestionManager()

class Answer(models.Model):
    text = models.TextField()
    added_at = models.DateTimeField(default=datetime.now)
    question = models.ForeignKey(Question)
    author = models.ForeignKey(User, blank=True, null=True)