from django.urls import path, include
from aboutus.views import aboutus

urlpatterns = [
    path('', aboutus, name='aboutus'),
]
