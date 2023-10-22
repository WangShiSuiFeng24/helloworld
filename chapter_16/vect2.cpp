// vect2.cpp -- methods and iterators
#include <iostream>
#include <string>
#include <vector>

struct Review {
    std::string title;
    int rating;
};

bool FillReview(Review &rr);
void ShowReview(const Review &rr);

int main()
{
    using std::cout;
    using std::endl;
    using std::vector;

    vector<Review> books;

    Review temp;
    while (FillReview(temp))
        books.push_back(temp);

    int num = books.size();

    if (num > 0)
    {
        cout << "Thank you. You entered the following!\n"
             << "Rating\tBook\n";

        for (int i = 0; i < num; ++i)
            ShowReview(books.operator[](i));

        cout << "Reprising:\n"
             << "Rating\tBook\n";

        vector<Review>::iterator pr;

        for (pr = books.begin(); pr != books.end(); pr++)
        {
            cout << pr->rating << "\t" << pr->title << endl;
            cout << pr.operator->()->rating << "\t" << pr.operator->()->title << endl;
        }
            // ShowReview(pr.operator*());

        vector<Review> oldlist(books);  // copy constructor used
        if (num > 3)
        {
            // remove 2 items
            cout << "Starting erase element!\n";
            vector<Review>::iterator its = books.erase(books.begin() + 1, books.begin() + 3);
            cout << its->rating << "\t" << its->title << endl;

            cout << "After erasure:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(pr.operator*());

            // insert 1 item
            cout << "Starting insert element!\n";
            vector<Review>::iterator iti = books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            cout << iti->rating << "\t" << iti->title << endl;

            cout << "After insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(pr.operator*());
        }

        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";
        for (pr = books.begin(); pr != books.end(); ++pr)
            ShowReview(pr.operator*());
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    return 0;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;

    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;

    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;

    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}