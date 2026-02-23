from django.db import models
from django.shortcuts import reverse , get_object_or_404
# Create your models here.
from categories.models import Category

class Product(models.Model):
    name = models.CharField(max_length=100)
    description = models.CharField(max_length=500)
    price = models.DecimalField(max_digits=10, decimal_places=2) 
    stock = models.IntegerField()
    image = models.ImageField(upload_to='products/images', null=True, blank=True)
    category = models.ForeignKey(
        Category,
        on_delete=models.CASCADE,
        null=True,
        blank=True,
        related_name='products'
    )
    # created_at = models.DateTimeField(auto_now_add=True, null=True)
    # updated_at = models.DateTimeField(auto_now=True, null=True)
    

    def __str__(self):
        return self.name
    
    @classmethod
    def get_all_products(cls):
        return cls.objects.all()
    
    @property
    def show_url(self):
        url = reverse('products.details',args=[self.id])
        return url
    
    @property
    def image_url(self):
        return f"/media/{self.image}"
    
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

    @classmethod
    def get_product(cls, product_id):
        return get_object_or_404(cls, id=product_id)

        