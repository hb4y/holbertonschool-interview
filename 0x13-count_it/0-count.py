#!/usr/bin/python3
"""
queries the Reddit API, parses the title
of all hot articles, and prints a sorted
count of given keywords
(case-insensitive, delimited by spaces
Javascript should count as javascript,
but java should not).
"""

import requests


def artic(subreddit, w_list, words_aux, words_aux_2, after="",):
    """ Process articles """
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    url += "?limit=100&after={}".format(after)
    res = requests.get(url, allow_redirects=False, headers={'User-agent': 'h'})

    if res.status_code != 200:
        return None

    articles = res.json().get("data").get("children")

    for article in articles:
        title_list = article.get("data").get("title").lower().split(" ")
        for title in title_list:

            if title in words_aux:
                words_aux[title] += 1
    after = res.json().get("data").get("after")

    if after is None:
        sorted_w = sorted(words_aux.items(), key=lambda t: t[::-1])
        sorted_w_desc = sorted(sorted_w, key=lambda tup: tup[1], reverse=True)
        for w in sorted_w_desc:
            if w[1] > 0:
                print("{}: {}".format(w[0], w[1] * words_aux_2[w[0]]))
        return

    return artic(subreddit, w_list, words_aux, words_aux_2, after)


def count_words(subreddit, w_list):
    """ Count the number of words """
    words_aux = {}
    words_aux_2 = {}
    w_list = [word.lower() for word in w_list]

    for w in w_list:
        if w not in words_aux:
            words_aux_2[w] = 1
            words_aux[w] = 0
        else:
            words_aux_2[w] += 1

    results = artic(subreddit, w_list, words_aux, words_aux_2)
