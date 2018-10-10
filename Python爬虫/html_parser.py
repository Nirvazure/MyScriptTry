class HtmlParser(object):
	"""这里应该是要大改的Html解析器"""
		
	def parse(self,page_url,html_cont):
		if page_url is None or html_cont is None:
			return

		soup=BeautifulSoup(html_cont,'html.parser',from_encoding='utf-8')
		new_urls=self._get_new_urls(page_url,soup)
		new_data=self._get_new_data(page_url,soup)
		return new_urls,new_data


	def _get_new_urls(self,page_url,soup):
		links=soup.find_all('a',href=re.compile(r"/view/\d+\.htm")) ##主要改这里\d代表数字
		for link in links:
			new_url=link['href'] ##创建新的Url，但是不完全下句代码装换成为完整的url
			new_full_url=urlparse.urljoin(page_url,new_url)
			new_urls.add(new_full_url)
		return new_urls

	def _get_new_data(self,page_url,soup):
		res_data={}	##字典类型

		res_data['url']=page_url

		title_node=soup.find('dd',class_="lemmaWgt-lemmaTitle-title").find("h1")	##得到标题标签，标题是子属性
		res_data['title']=title_node.get_text()

		summary_node=soup.find('div',class_="lemma-summary")
		res_data['summary']=summary_node.get_text()

		return res_data