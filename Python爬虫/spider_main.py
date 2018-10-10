if __name__=="main":
	root_url="https://baike.baidu.com/item/Python/407313"
	obj_spider=SpiderMain()
	obj_spider.craw(root_url)

class SpiderMain(object):
	"""爬虫调度器"""
	def __init__(self):
		self.urls = url_manager.UrlManager()
		self.downloader=html_downloader.HtmlDownloader()
		self.parser=html_parser.HtmlParser()
		self.outputer=html_output.HtmlOutputer()

	def craw(self,root_url):
		count=1 #计数器
		self.urls.add_new_url(root_url)
		while self.urls.has_new_utl():
			try:
				new_url=self.urls.get_new_url()
				print ('craw %d : %s' % (count,new_url))
				html_cont=self.downloader.download(new_url)
				new_urls,new_data=self.parser.parse(new_url,html_cont)
				self.urls.add_new_urls(new_urls)
				self.outputer.collect_data(new_data)
				
				if count==1000:
					break

				count=count+1
			except:
				print('craw failed')

		self.outputer.output_html()
		