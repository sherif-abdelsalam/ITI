from django.db import models
from django.shortcuts import reverse, get_object_or_404

# Create your models here.

class Category(models.Model):
    name = models.CharField(max_length=100)
    description = models.CharField(max_length=500)
    logo = models.ImageField(upload_to='categories/images', null=True, blank=True)

    def __str__(self):
        return self.name
    
    @classmethod
    def get_all_categories(cls):
        return cls.objects.all()
    
    @property
    def show_url(self):
        url = reverse('categories.show', args=[self.id])
        return url
    
    # @property
    # def edit_url(self):
    #     return reverse("categories.edit", args=[self.id])
    
    # @property
    # def delete_url(self):
    #     return reverse("categories.delete", args=[self.id])
    
    @classmethod
    def get_category(cls, category_id):
        return get_object_or_404(cls, id=category_id)
    
    @classmethod
    def delete_category_by_id(cls, category_id):
        category = get_object_or_404(cls, id=category_id)
        category.delete()