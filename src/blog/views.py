from django.shortcuts import render
from django.http import Http404
from .models import BlogPost


def blogPostDetail(request, post_id):
    try:
        obj = BlogPost.objects.get(id = post_id)
    except:
        raise Http404
    templateName = "blogPostDetail.html"
    context = {"object": obj}
    return render(request,templateName,context) 