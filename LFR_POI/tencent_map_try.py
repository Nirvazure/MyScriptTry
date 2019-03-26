from urllib import request
import json

tmap_web_key = 'MZMBZ-Q2XHI-5LBGM-5AIZQ-CMIFZ-DNFKP'
tmap_poi_search_url = 'https://apis.map.qq.com/ws/place/v1/search'

def getpoi_page():
    tmap_req_url = tmap_poi_search_url+'?boundary=nearby(39.908491,116.374328,1000)&page_size=20&page_index=1&keyword=KFC&orderby=_distance&key='+tmap_web_key
    data = ''
    with request.urlopen(tmap_req_url) as f:
        data = f.read()
        data = data.decode('utf-8')
    return data

result = getpoi_page()
result = json.loads(result)
pois = result['data']

print(pois)
for i in range(len(pois)):
    print(pois[i]['id']+'\t'+str(pois[i]['location'])+'\t'+pois[i]['title'])