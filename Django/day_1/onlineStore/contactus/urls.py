
from django.urls import path, include

from contactus.views import contactus

urlpatterns = [
    path('', contactus, name='contactus')
]