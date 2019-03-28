from urllib import request
import argparse
import json

#CMD MENU
parser = argparse.ArgumentParser(prog='POI Module',description='Find POIs base on your point and keyword',epilog='Did your konw the usage?Please enjoy it')
parser.add_argument('point', metavar='N', type=float, nargs=2,
                    help='point')
parser.add_argument('-r','--radius',default=1000.0,type=float,
                    help='radius of POI area default 1000 m')
parser.add_argument('-kc','--keycode',default='',type=str,
                    help='6 bit number like 010100')
args = parser.parse_args()

# Hyper parameter
amap_web_key = '478303ba07433ee71b52e8924c3a56db'
point = [args.point[0],args.point[1]]
radius = args.radius
keycode = args.keycode
poi_search_url = "http://restapi.amap.com/v3/place/around"

def getpoi_page(point,radius,keycode):
    req_url = 'http://restapi.amap.com/v3/place/around?'+'key='+amap_web_key+'&location='+str(point[0])+','+str(point[1])+'&keywords=&types='+keycode+'&radius='+str(radius)+'&offset=20&page=1&extensions=all'
    data = ''
    with request.urlopen(req_url) as f:
        data = f.read()
        data = data.decode('utf-8')
    return data

print(args)
result=getpoi_page(point,radius,keycode)
result=json.loads(result)

print(result)
pois=result['pois']
for i in range(len(pois)):
    print(pois[i]['id']+'\t'+pois[i]['location']+'\t'+pois[i]['name'])
