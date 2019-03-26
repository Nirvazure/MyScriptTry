# baidu map try
from urllib import request
import json

point=[39.9,116.4]
radius=1000.0

bmap_web_key = 'RKdmGLIj21REUjYIez9FICyLQ1YcfCP6'
bmap_poi_place_url = 'http://api.map.baidu.com/place/v2/'

def getpoi_page(point,radius):
    bmap_req_url = bmap_poi_place_url+'search?query=ATM&location='+str(point[0])+','+str(point[1])+'&radius='+str(radius)+'&output=json&ak='+bmap_web_key
    data = ''
    with request.urlopen(bmap_req_url) as f:
        data = f.read()
        data = data.decode('utf-8')

    result=json.loads(data)
    pois=result['results']
    return pois

pois=getpoi_page(point,radius)

for i in range(len(pois)):
    print(str(pois[i]['location'])+'\t'+pois[i]['name'])