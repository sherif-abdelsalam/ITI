from django.urls import path

from categories.views import category_list, create_category_with_model_form, category_show

urlpatterns = [
    path('', category_list, name='categories.index'),
    path('create/', create_category_with_model_form, name='categories.create'),
    path('<int:category_id>/', category_show, name='categories.show'),

] 