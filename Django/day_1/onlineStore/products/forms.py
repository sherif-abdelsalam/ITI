

from django import forms

from products.models import Product


class ProductModelForm(forms.ModelForm):
    # use model to create form  --> fields with its basic validation based on
    # information given by model ??

    class Meta: 
        model = Product
        fields = ['name','description','price','stock','image']



    

    
