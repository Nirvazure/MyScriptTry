import urllib.request
import json
import os

v_herolist_url = urllib.request.urlopen("http://pvp.qq.com/web201605/js/herolist.json")
v_herolist = v_herolist_url.read().decode('utf-8')
v_hero = v_herolist.encode('utf8')[3:].decode('utf-8')
hero_json = json.loads(v_hero)
hero_num = len(hero_json)

hero_dir = './img/'
if not os.path.exists(hero_dir):
    os.mkdir(hero_dir)
for num in range(hero_num):
   skinsname =  hero_json[num]['skin_name'].split("|")
   print(hero_json[num]['cname'])
   print(skinsname)
   input()
   for i in range(len(skinsname)):
        skin_name = hero_json[num]['ename']
        skin_url = 'http://game.gtimg.cn/images/yxzj/img201606/skin/hero-info/'+str(skin_name)+'/'+str(skin_name)+'-bigskin-'+str(i+1)+'.jpg'
        save_url=hero_dir+str(skin_name)+"_"+str(i+1)+".jpg"
        # urllib.request.urlretrieve(skin_url,save_url)