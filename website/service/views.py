from django.shortcuts import render

def post_list(request):
    return render(request, 'service/post_list.html', {})