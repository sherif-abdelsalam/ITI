from django.db import models
from django.shortcuts import reverse , get_object_or_404
# Create your models here.

class Product(models.Model):
    name = models.CharField(max_length=100)
    description = models.CharField(max_length=500)
    price = models.DecimalField(max_digits=10, decimal_places=2) 
    stock = models.IntegerField()
    image = models.CharField(max_length=200) 
    

    def __str__(self):
        return self.name
    
    @classmethod
    def get_all_products(cls):
        return cls.objects.all()
    
    @property
    def show_url(self):
        url = reverse('products.details',args=[self.id])
        return url
    
    def delete_url(self):
        delete_url = reverse("products.delete", args=[self.id])
        return delete_url
    
    def edit_url(self):
        edit_url = reverse("products.edit", args=[self.id])
        return edit_url
    
    @classmethod
    def delete_product_by_id(cls, product_id):
        product = get_object_or_404(cls, id=product_id)
        product.delete()
        