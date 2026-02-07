from django.urls import path

from products.views import product_delete, product_edit, product_list, product_detail, product_create

urlpatterns = [
    path('', product_list, name='products.index'),
    path('<int:product_id>/', product_detail, name='products.details'),
    path('delete/<int:product_id>', product_delete, name='products.delete'),
    path('create/', product_create, name='products.create'),    
    path('edit/<int:product_id>', product_edit, name='products.edit'),
]   