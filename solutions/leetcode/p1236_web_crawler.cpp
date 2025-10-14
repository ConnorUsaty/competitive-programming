/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
private:
    void dfs(const string& host, const string& url, HtmlParser hp, unordered_set<string>& vis) {
        vis.insert(url);
        vector<string> adj = hp.getUrls(url);
        for(const std::string v : adj) {
            std::string host_v = get_hostname(v);
            if(vis.find(v) == vis.end() && host == host_v) {
                dfs(host, v, hp, vis);
            }
        }
    }

    std::string get_hostname(const std::string& s) {
        int idx = min(s.size(), s.find('/', 7));
        return s.substr(7, idx-7);
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        std::string hostname = get_hostname(startUrl);
        unordered_set<string> visited;
        dfs(hostname, startUrl, htmlParser, visited);
        return vector<string>(visited.begin(), visited.end());
    }
};

// can do s.find(c, idx) to find first occurence of c AT or AFTER idx