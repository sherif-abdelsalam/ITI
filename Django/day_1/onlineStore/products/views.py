from django.shortcuts import render, redirect

from products.models import Product
# Create your views here.
# products = [
#     {
#         "id": 1,
#         "name": "Apple iPhone 15",
#         "image": "online-store.jpg",
#         "price": 999.99,
#         "stock": 10
#     },
#     {
#         "id": 2,
#         "name": "Samsung Galaxy S23",
#         "image": "online-store.jpg",
#         "price": 899.99,
#         "stock": 15
#     },
#     {
#         "id": 3,
#         "name": "Sony WH-1000XM5 Headphones",
#         "image": "online-store.jpg",
#         "price": 349.99,
#         "stock": 20
#     },
#     {
#         "id": 4,
#         "name": "Dell XPS 13 Laptop",
#         "image": "online-store.jpg",
#         "price": 1299.99,
#         "stock": 5
#     },
#     {
#         "id": 5,
#         "name": "Apple Watch Series 9",
#         "image": "online-store.jpg",
#         "price": 399.99,
#         "stock": 12
#     }
# ]


def product_list(request):

    products = Product.get_all_products()
    return render(request, 'products/index.html', {'products': products})

def product_detail(request, product_id):
    product = Product.objects.get(id=product_id)
    return render(request, 'products/product_detail.html', {'product': product})
    
def product_delete(request, product_id):
    Product.delete_product_by_id(product_id)
    return redirect('products.index')

def product_create(request):
    # print("------------------------------")
    # print(request.POST)
    if request.method == "POST":
        name = request.POST['name']
        description = request.POST['description']
        price = request.POST['price']
        stock = request.POST['stock']
        image = request.POST['image']
        product = Product(
            name=name,
            description=description,
            price=price,
            stock=stock,
            image=image
        )
        product.save()
        return redirect(product.show_url)

    return render(request, 'products/product_create.html')


def product_edit(request, product_id):
    product = Product.objects.get(id=product_id)
    if request.method == "POST":
        product.name = request.POST['name']
        product.description = request.POST['description']
        product.price = request.POST['price']
        product.stock = request.POST['stock']
        product.image = request.POST['image']
        product.save()
        return redirect(product.show_url)

    return render(request, 'products/product_create.html', {'product': product})