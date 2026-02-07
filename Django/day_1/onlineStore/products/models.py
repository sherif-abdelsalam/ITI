from django.db import models
from django.urls import reverse

# Create your models here.

class Product(models.Model):
    name = models.CharField(max_length=100)
    description = models.CharField(max_length=500)
    price = models.DecimalField(max_digits=10, decimal_places=2) 
    stock = models.IntegerField()
    image = models.CharField(max_length=200) 
    

    def __str__(self):
        return self.name
    
    # @property
    # def show_url(self):
    #     url = reverse('products.product_detail',args=[self.id])
    #     return url