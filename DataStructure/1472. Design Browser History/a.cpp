class BrowserHistory {
public:
  list<string> history;
  list<string>::iterator cur;

  BrowserHistory(string homepage) {
    history.push_back(homepage);
    cur = history.begin();
  }

  void visit(string url) {
    // clear forward history
    history.erase(next(cur), history.end());
    // add new url to history
    history.push_back(url);
    cur = prev(history.end());
  }

  string back(int steps) {
    while (steps > 0 && cur != history.begin()) {
      cur--;
      steps--;
    }
    return *cur;
  }

  string forward(int steps) {
    while (steps > 0 && cur != prev(history.end())) {
      cur++;
      steps--;
    }
    return *cur;
  }
};
