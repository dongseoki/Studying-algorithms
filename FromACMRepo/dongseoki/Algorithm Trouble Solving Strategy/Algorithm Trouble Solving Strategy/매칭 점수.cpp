#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#define F(p,q,r) for(int p=q;p<r;p++)

using namespace std;

class Page {
public:
    int basic_point;
    int out_link_num;
    double link_point;
    vector<int> iOPSWLTP; //index_of_pages_which_link_this_page
    double match_point;
    Page(){
        this->basic_point = 0;
        this->out_link_num = 0;
        this->link_point = 0;
        this->match_point = 0;
    }
};


void pushUrlPageIdx(int idx, map<string, int>& urlmap, vector<string>& pages) {
    string forurlpattern = "<meta property=\"og:url\" content=\"";
    int distance = forurlpattern.size();
    int p1 = pages[idx].find(forurlpattern);
    int p2 = p1 + distance;

    int i = 0;
    while (true) {
        if (pages[idx][p2 + i] == '\"') {
            break;
        }
        i++;
    }
    string myurl = pages[idx].substr(p2, i);
    urlmap[myurl] = idx;
}

void search_word(int idx, string word, vector<string>& pages, vector<Page>& data_vector) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    int find_idx = 0;
    string lowered_page = pages[idx];
    transform(lowered_page.begin(), lowered_page.end(), lowered_page.begin(), ::tolower);
    while (true) {
        int word_p = lowered_page.find(word, find_idx);
        if (word_p == string::npos) {
            break;
        }

        char pre_ch = lowered_page[word_p - 1];
        char post_ch = lowered_page[word_p + word.size()];
        if (('a' <= pre_ch && pre_ch <= 'z')
            || ('A' <= pre_ch && pre_ch <= 'Z')
            || ('a' <= post_ch && post_ch <= 'z')
            || ('A' <= post_ch && post_ch <= 'Z')) {
            // Ʋ�� �ܾ�.
            // �ܾ�� ���ĺ��� ������ �ٸ� ��� ���ڷ� �����Ѵ�.
            find_idx++;

        }
        else {
            // �´� �ܾ�.
            data_vector[idx].basic_point++;
            find_idx = word_p + word.size();
        }


    }
}

void caculate_outlink(int idx, map<string, int>& urlmap, vector<string>& pages, vector<Page>& data_vector) {
    int find_idx = 0;
    while (true) {
        string forurlpattern = "<a href=\"";
        int distance = forurlpattern.size();
        int p1 = pages[idx].find(forurlpattern, find_idx);

        if (p1 == string::npos) {
            break;
        }

        int p2 = p1 + distance;

        int i = 0;
        while (true) {
            if (pages[idx][p2 + i] == '\"') {
                break;
            }
            i++;
        }
        string outlink = pages[idx].substr(p2, i);
        if (urlmap.find(outlink) != urlmap.end()) {
            
            data_vector[urlmap[outlink]].iOPSWLTP.push_back(idx);
            
        }
        data_vector[idx].out_link_num++;
        find_idx = p2 + i;

    }
    
}

void caculate_link_match_point(int idx, map<string, int>& urlmap, vector<string>& pages, vector<Page>& data_vector) {
    // 1. ��ũ ����Ʈ
    for (auto item : data_vector[idx].iOPSWLTP) {
        data_vector[idx].link_point += (double)data_vector[item].basic_point / data_vector[item].out_link_num;
    }
    // 2. ��ġ ����Ʈ.
    data_vector[idx].match_point = data_vector[idx].basic_point + data_vector[idx].link_point;

}

int solution(string word, vector<string> pages) {
    vector<int> v1;
    map<string, int> urlmap;
    v1.push_back(1);

    vector<Page> data_vector(pages.size(), Page());
    // map ��  url  , page index �� �ǵ��� ���� �ִ´�.
    F(idx, 0, pages.size()) {
        pushUrlPageIdx(idx, urlmap, pages);
        
    }
    // �ܾ �˻��Ѵ�. -> �⺻ ������ ���� ����.
    // �ܾ ������ ��ġ�ϴ� ��츸 ��.
    
    F(idx, 0, pages.size()) {
        search_word(idx, word, pages, data_vector);
    }


    //3.�ܺ� ��ũ ���� ����Ѵ�. �׸���  IOPSWLTP�� ���� ä���.
    F(idx, 0, pages.size()) {
        caculate_outlink(idx, urlmap, pages, data_vector);
    }
    
    //4. ��ũ ������ ����Ѵ�. , ��Ī ������ ����Ѵ�.
    F(idx, 0, pages.size()) {
        caculate_link_match_point(idx, urlmap, pages, data_vector);
    }

    //5. ��Ī ������ �� ���� ū ���߿� ���� ���� �ε����� ��ȯ�Ѵ�.

    double max_match_point = -1;
    int answer = 0;
    F(idx, 0, pages.size()) {
        if (max_match_point < data_vector[idx].match_point) {
            max_match_point = data_vector[idx].match_point;
            answer = idx;
        }
    }

    return answer;
}

int main(void) {
    //cout << solution("blind", { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" });

    //cout << solution("Muzi", { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>" });


    string long_string = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>";


}