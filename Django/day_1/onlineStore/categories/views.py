from django.shortcuts import render, redirect
from categories.models import Category
from categories.forms import CategoryForm
# Create your views here.


def category_list(request):
    categories = Category.objects.all()
    return render(request, 'categories/categories.html', {'categories': categories})    

def create_category_with_model_form(request):
    form = CategoryForm()
    if request.method == "POST":
        form = CategoryForm(request.POST, request.FILES)
        print(request.FILES)
        if form.is_valid():
            category = form.save(commit=True)
            return redirect(category.show_url)

    return render(request, 'categories/create_category.html',
                  context={'form': form})

def category_show(request, category_id):
    category = Category.objects.get(id=category_id)
    products = category.products.all()
    return render(request, 'categories/category_show.html', context={'category': category, 'products': products})

