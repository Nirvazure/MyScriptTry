from bs4 import BeautifulSoup
from urllib import request

url="https://movie.douban.com/"
page = request.urlopen(url).read().decode('utf-8')
soup = BeautifulSoup(page)

# print(soup.prettify())
print(soup.find_all("li"))