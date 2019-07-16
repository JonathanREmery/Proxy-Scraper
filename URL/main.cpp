#include <vector>
#include <fstream>
#include "request.h"
#include "parse.h"

int main(void)
{
	
	std::string html = get("https://free-proxy-list.net/");
	
	std::vector<std::string> proxies_raw = split(split(split(html, "<th class=\'hm\'>Last Checked</th></tr></thead><tbody><tr><td>")[1], "<tfoot><tr><th class=\"input\"><input type=\"text\" />")[0], "</tr><tr><td>");
	std::vector<std::vector<std::string>> proxies;
	
	for (int i = 0; i < proxies_raw.size(); i++) {
		std::vector<std::string> info;
		info.push_back(split(proxies_raw[i], "</td><td>")[0]);
		info.push_back(split(proxies_raw[i], "</td><td>")[1]);
		proxies.push_back(info);
	}

	std::string out;

	for (int i = 0; i < proxies.size(); i++) {
		out.append(proxies[i][0] + " | " + proxies[i][1] + "\n");
	}

	std::cout << "Scraped " << count(out, "\n") << " IP\'s!" << std::endl;
	
	std::ofstream output; 
	output.open("C:\\Users\\Jonathan\\Desktop\\output.txt");
	output << out;
	output.close();

	return 0;
}