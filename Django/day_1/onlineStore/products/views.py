from django.shortcuts import render
from django.http import HttpResponse
# Create your views here.
# Hard-coded list of products
products = [
    {
        "id": 1,
        "name": "Apple iPhone 15",
        "image": "assets/online-store.jpg",
        "price": 999.99,
        "stock": 10
    },
    {
        "id": 2,
        "name": "Samsung Galaxy S23",
        "image": "assets/online-store.jpg",
        "price": 899.99,
        "stock": 15
    },
    {
        "id": 3,
        "name": "Sony WH-1000XM5 Headphones",
        "image": "assets/online-store.jpg",
        "price": 349.99,
        "stock": 20
    },
    {
        "id": 4,
        "name": "Dell XPS 13 Laptop",
        "image": "assets/online-store.jpg",
        "price": 1299.99,
        "stock": 5
    },
    {
        "id": 5,
        "name": "Apple Watch Series 9",
        "image": "assets/online-store.jpg",
        "price": 399.99,
        "stock": 12
    }
]


def product_list(request):
    return render(request, 'products/index.html', {'products': products})

def product_detail(request, product_id):
    
    product = filter(lambda p: p['id'] == product_id, products) 
    product_list = list(product)
    if product_list:
        return render(request, 'products/product_detail.html', {'product': product_list[0]})
    else:
        return HttpResponse("Product not found", status=404)