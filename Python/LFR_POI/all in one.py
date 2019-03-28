from urllib import request
import json

#Hyper parameters
bmap_web_key = 'RKdmGLIj21REUjYIez9FICyLQ1YcfCP6'
bmap_poi_url = 'http://api.map.baidu.com/place/v2/'

tmap_web_key = 'MZMBZ-Q2XHI-5LBGM-5AIZQ-CMIFZ-DNFKP'
tmap_poi_url = 'https://apis.map.qq.com/ws/place/v1/search'

amap_web_key = '478303ba07433ee71b52e8924c3a56db'
amap_poi_url = 'http://restapi.amap.com/v3/place/around'

point=[39.9,116.4]
radius=1000

def getpoi_page(point,radius,map_id=0):
    '''
    input:
    output:data in json format
    ''' 
    req_url = ''
    data=''
    if map_id==1:
        req_url=tmap_poi_url+'?boundary=nearby('+str(point[0])+','+str(point[1])+','+str(radius)+')&page_size=20&page_index=1&keyword=ATM&orderby=_distance&key='+tmap_web_key
    elif map_id==2:
        req_url=bmap_poi_url+'search?query=ATM&location='+str(point[0])+','+str(point[1])+'&radius='+str(radius)+'&output=json&ak='+bmap_web_key
    else:
        req_url='http://restapi.amap.com/v3/place/around?key='+amap_web_key+'&location='+str(point[0])+','+str(point[1])+'&keywords=ATM&radius='+str(radius)+'&offset=20&page=1&extensions=all'

    with request.urlopen(req_url) as f:
        data = f.read()
        data = data.decode('utf-8')
    result=json.loads(data)
    return result

print("======================a map===========================") 
pois_amap=getpoi_page(point,radius,0)
pois_amap=pois_amap['pois']
for i in range(len(pois_amap)):
    print(pois_amap[i]['location']+'\t'+pois_amap[i]['name'])

print("======================baidu map===========================") 

pois_bmap=getpoi_page(point,radius,2)
pois_bmap=pois_bmap['results']
for i in range(len(pois_bmap)):
    print(str(pois_bmap[i]['location']['lat'])+','+str(pois_bmap[i]['location']['lng'])+'\t'+pois_bmap[i]['name'])

print("======================tencent map===========================")

pois_tmap=getpoi_page(point,radius,1)
pois_tmap=pois_tmap['data']
for i in range(len(pois_tmap)):
    print(str(pois_tmap[i]['location']['lat'])+','+str(pois_tmap[i]['location']['lng'])+'\t'+pois_tmap[i]['title'])