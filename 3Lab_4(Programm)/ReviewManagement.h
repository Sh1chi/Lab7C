#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class ReviewManagement {
    vector<T> reviews;

public:
    void addReview(T review) {
        reviews.push_back(review);
    }

    void displayReviews() {
        for (const auto& review : reviews) {
            cout << "- " << review << endl;
        }
    }
};

