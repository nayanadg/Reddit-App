#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include <vector>
using namespace std;

class User;
class SubReddit;
class Post;
class AddPost;
class Moderator;
class Features;
class Comment;
class Award;
class Reply;
class MyException;

class Award
{
public:
    int awardId;
    string name;
    int points;
    Award() : awardId(0), name(""), points(0)
    {
    }
    Award(int a, string n, int p) : awardId(a), name(n), points(p)
    {
    }
    void printAward()
    {
        cout << "Award ID: " << awardId << "Award Name: " << name << "Points: " << points;
    }
};

class Reply
{
public:
    int replyId;
    string text;
    int upVotes;
    Award *awards = new Award;
    vector<Reply> subordinates;
    Reply() : replyId(0), text(""), upVotes(0)
    {
    }
    Reply(int r, string t, int u) : replyId(r), text(t), upVotes(u)
    {
    }
    void printReply()
    {
        cout << "Reply Id: " << replyId << " Reply: " << text << "Upvotes: " << upVotes;
    }
    void upVote()
    {
        upVotes += 1;
        cout << "Upvoted" << endl;
    }
    void downVote()
    {
        upVotes -= 1;
        cout << "Downvoted" << endl;
    }
    void addReply(Reply r)
    {
        subordinates.push_back(r);
        cout << "Replied" << endl;
    }
    void printSubordinates(vector<Reply> r)
    {
        vector<Reply>::iterator it;
        for (it = r.begin(); it != r.end(); it++)
        {
            it->printReply();
        }
    }
};

class Comment
{
public:
    int commId;
    string text;
    int upVotes;
    Award *awards = new Award;
    int awardCount = 0;
    Reply *replies = new Reply;
    int replyCount = 0;
    Comment() : commId(0), text(""), upVotes(0)
    {
    }
    Comment(int c, string t, int u) : commId(c), text(t), upVotes(u)
    {
    }
    void printComment()
    {
        cout << "Comment Id: " << commId << "Comment: " << text << "Up votes " << upVotes << endl;
    }
    void addReply(Reply r)
    {
        replies[replyCount++] = r;
        cout << "Commented" << endl;
    }
    void upVote()
    {
        upVotes += 1;
        cout << "Upvoted" << endl;
    }
    void downVote()
    {
        upVotes -= 1;
        cout << "Downvoted" << endl;
    }
    void addAward(Award a)
    {
        awards[awardCount++] = a;
        cout << "Awarded" << endl;
    }
};

class Post
{
public:
    int postId;
    string postTitle;
    int upVotes;
    string text;
    int imageId;
    int videoId;
    Award *awards = new Award;
    int awardCount = 0;
    Comment *comments = new Comment;
    int commCount = 0;
    Post() : postId(0), postTitle(""), text(""), imageId(0), videoId(0)
    {
    }
    Post(int p, string pt, string t, int i, int v) : postId(p), postTitle(pt), text(t), imageId(i), videoId(v)
    {
    }
    void printDetails()
    {
        cout << "Post Details: " << endl;
        cout << "Post ID: " << postId << "  Post Title: " << postTitle << endl;
        cout << "Text: " << text << " Image ID: " << imageId << " Video ID: " << videoId << endl;
    }
    void upVote()
    {
        upVotes += 1;
        cout << "Upvoted" << endl;
    }
    void downVote()
    {
        upVotes -= 1;
        cout << "Downvoted" << endl;
    }
    void addComments(Comment c)
    {
        comments[commCount++] = c;
        cout << "Commented" << endl;
    }
    void addAward(Award a)
    {
        awards[awardCount++] = a;
        cout << "Awarded" << endl;
    }
};

class SubReddit
{
public:
    string name;
    string about;
    string category;
    int members;
    Post *posts = new Post;
    int count = 0;
    SubReddit() : name(""), about(""), category(""), members(0)
    {
    }
    SubReddit(string n, string a, string c, int m) : name(n), about(a), category(c), members(m)
    {
    }
    void printDetails()
    {
        cout << "Sub-Reddit details:" << endl;
        cout << "Sub-reddit name: " << name << "About: " << about << "category: "
             << "members: " << members << endl;
    }
};

class AddPost
{
public:
    void postText(SubReddit s, Post p)
    {
        int i = s.count;
        s.posts[i] = p;
        s.count++;
        cout << "Text posted" << endl;
    }
    void postImage(SubReddit s, Post p)
    {
        int i = s.count;
        s.posts[i] = p;
        s.count++;
        cout << "Image posted" << endl;
    }
    void postVideo(SubReddit s, Post p)
    {
        int i = s.count;
        s.posts[i] = p;
        s.count++;
        cout << "Video posted" << endl;
    }
    void printPostDetails(Post P)
    {
        cout << "Your Text post: " << endl;
        cout << "Post Id: " << P.postId << endl;
        cout << P.text << endl;
        cout << "Your Image post: " << endl;
        cout << "Image Id: " << P.imageId << endl;
        cout << "Your Video post: " << endl;
        cout << "Video Id: " << P.videoId << endl
             << endl;
    }
};

class User
{
public:
    string userName;
    string gender;
    // string *interests;
    int karma;
    int redditAge;
    int coins;
    bool premium;
    string password;
    SubReddit *subReddits = new SubReddit;
    int count = 0;
    User() : userName(""), gender(""), karma(0), redditAge(0), coins(0), premium(false), password("")
    {
    }
    User(string u, string g, int k, int r, int c, bool p, string pw) : userName(u), gender(g), karma(k), redditAge(r), coins(c), premium(p), password(pw)
    {
    }
    void printDetails()
    {
        cout << "User deatils:" << endl;
        cout << "User Name: " << userName << endl;
        cout << "Gender: " << gender << endl;
        cout << "Karma :" << karma << endl;
        cout << "Reddit age: " << redditAge << endl;
        cout << "Coins: " << coins << endl;
        cout << "Premium: " << premium << endl;
    }
    void buyCoins(int amt)
    {
        coins += 2 * amt;
        cout << "Coins bought" << endl;
    }
    void buyPremium()
    {
        int choice;
        cout << "Premium Plans" << endl;
        cout << "1. 500 for 10 days" << endl;
        cout << "2. 600 for 15 days" << endl;
        cout << "3. 750 for 20 days" << endl;
        cout << "4. 1000 for 30 days" << endl;
        cout << "Enter plan choice: " << endl;
        cin >> choice;
        if (choice == 1)
        {
            premium = true;
            cout << "You have gained the access to premium for 10 days " << endl;
        }
        else if (choice == 2)
        {
            premium = true;
            cout << "You have gained the access to premium for 15 days." << endl;
        }
        else if (choice == 3)
        {
            premium = true;
            cout << "You have gained the access to premium for 20 days." << endl;
        }
        else if (choice == 4)
        {
            premium = true;
            cout << "You have gained the access to premium for 30 days." << endl;
        }
        else
        {
            premium = false;
            cout << "You have no premimum access." << endl;
        }
    }
    void joinSubreddit(SubReddit s)
    {
        subReddits[count] = s;
        count++;
        cout << "Subreddit created/joined" << endl;
    }
    void addKarma()
    {
        karma += 10;
        cout << "Karma added" << endl;
    }
};

class Moderator : public User
{
public:
    Moderator(string u, string g, int k, int r, int c, bool p, string pw) : User(u, g, k, r, c, p, pw)
    {
    }
    void createSubReddit(SubReddit s1)
    {
        subReddits[count++] = s1;
        cout << "Subreddit created" << endl;
    }
    void printDetails()
    {
        cout << "User details:" << endl;
        cout << "User Name: " << userName << endl;
        cout << "Gender: " << gender << endl;
        cout << "karma :" << karma << endl;
        cout << "Reddit age: " << redditAge << endl;
        cout << "Coins: " << coins << endl;
        cout << "Premium: " << premium << endl;
        cout << "Number of subreddits created: " << count << endl;
    }
};

class MyException
{
public:
    int getId()
    {
        int id;
        cout << "Enter ID: ";
        cin >> id;
        if (id == 0)
            throw invalid_argument("ID cannot be zero");
        else if (id < 0)
            throw logic_error("ID cannot be negative");
        return id;
    }
    void checkKarma(User u)
    {
        if (u.karma < 50)
            throw out_of_range("Not enough karma");
    }
    void checkCoins(User u)
    {
        if (u.coins < 50)
            throw out_of_range("Not enough coins");
    }
};

vector<SubReddit> allSubs;
vector<User> allUsers;
vector<Post> allPosts;

class Features
{
public:
    void displayFeatures()
    {
        int choice;
        cout << "Features: " << endl;
        cout << "1. Search SubReddit" << endl;
        cout << "2. Explore" << endl;
        cout << "3. Chats" << endl;
        cout << "4. Notifications" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
            search();
        else if (choice == 2)
            explore();
        else if (choice == 3)
            chats();
        else if (choice == 4)
            notifications();
        else
            cout << "Incorrect choice" << endl;
    }
    void search()
    {
        string name, text, method, user;
        cout << "Enter SubReddit name: ";
        cin >> name;
        int id, k, m, ch, ch1, pts, ch2;
        Comment c;
        Reply r;
        MyException me;
        Award a;
        for (int i = 0; i < allSubs.size(); i++)
        {
            if (allSubs[i].name == name)
            {
                allSubs[i].printDetails();
                cout << "Enter 1 to join subreddit: ";
                cin >> ch1;
                if (ch1 == 1)
                {
                    cout << "Enter user name: ";
                    cin >> user;
                    for (int k = 0; k < allUsers.size(); k++)
                    {
                        if (allUsers[k].userName == user)
                        {
                            allUsers[k].joinSubreddit(allSubs[i]);
                        }
                    }
                }
                else
                {}
                for (int j = 0; j <= allSubs[i].count; j++)
                {
                    allSubs[i].posts[j].printDetails();
                    cout << "1. Upvote" << endl;
                    cout << "2. Downvote" << endl;
                    cout << "3. Award" << endl;
                    cout << "4. Comments" << endl;
                    cout << "5. Share" << endl;
                    cout << "6. Exit" << endl;
                    bool upVote, downVote;
                    int choice;
                    cout << "Enter choice: ";
                    cin >> choice;
                        switch (choice)
                        {
                        case 1:
                            if (upVote == false)
                            {
                                allSubs[i].posts[j].upVote();
                                upVote = true;
                            }
                            break;
                        case 2:
                            if (downVote == false)
                            {
                                allSubs[i].posts[j].downVote();
                                downVote = true;
                            }
                            break;
                        case 3:
                            try
                            {
                                id = me.getId();
                                a.awardId = id;
                                cout << "Enter award name: ";
                                cin >> name;
                                cout << "Enter points: ";
                                cin >> pts;
                                a.name = name;
                                a.points = pts;
                                allSubs[i].posts[j].addAward(a);
                            }
                            catch (invalid_argument i)
                            {
                                cout << i.what() << endl;
                            }
                            catch (logic_error l)
                            {
                                cout << l.what() << endl;
                            }
                            break;
                        case 4:
                            for (k = 0; k < allSubs[i].posts[j].commCount; k++)
                            {
                                allSubs[i].posts[j].comments[k].printComment();
                                cout << "1. Add reply" << endl;
                                cout << "2. UpVote" << endl;
                                cout << "3. DownVote" << endl;
                                bool upVote1, downVote1;
                                cout << "Enter choice: " << endl;
                                cin >> ch;
                                if (ch == 1)
                                {
                                    try
                                    {
                                        id = me.getId();
                                        r.replyId = id;
                                        cout << "Enter text: ";
                                        cin >> text;
                                        r.text = text;
                                        allSubs[i].posts[j].comments[k].addReply(r);
                                    }
                                    catch (invalid_argument i)
                                    {
                                        cout << i.what() << endl;
                                    }
                                    catch (logic_error l)
                                    {
                                        cout << l.what() << endl;
                                    }
                                }
                                else if (ch == 2)
                                {
                                    if (upVote1 == false)
                                    {
                                        allSubs[i].posts[j].comments[k].upVote();
                                        upVote1 = true;
                                    }
                                }
                                else if (ch == 3)
                                {
                                    if (downVote1 == false)
                                    {
                                        allSubs[i].posts[j].comments[k].downVote();
                                        downVote1 = true;
                                    }
                                }
                                else
                                {
                                }
                                for (m = 0; m <= allSubs[i].posts[j].comments[k].replyCount; m++)
                                {
                                    allSubs[i].posts[j].comments[k].replies[m].printReply();
                                    Reply r1 = allSubs[i].posts[j].comments[k].replies[m];
                                    allSubs[i].posts[j].comments[k].replies[m].printSubordinates(r1.subordinates);
                                    cout<<"Enter 1 to reply: ";
                                    cin>> ch2;
                                    if(ch2 == 1)
                                    {
                                        try
                                    {
                                        id = me.getId();
                                        r.replyId = id;
                                        cout << "Enter text: ";
                                        cin >> text;
                                        r.text = text;
                                        allSubs[i].posts[j].comments[k].replies[m].addReply(r);
                                    }
                                    catch (invalid_argument i)
                                    {
                                        cout << i.what() << endl;
                                    }
                                    catch (logic_error l)
                                    {
                                        cout << l.what() << endl;
                                    }
                                    
                                    }
                                }
                            }
                            cout << "1. Add comment" << endl;
                            cout << "0. Exit" << endl;
                            cin >> ch;
                            if (ch == 1)
                            {
                                try
                                {
                                    id = me.getId();
                                    c.commId = id;
                                    cout << "Enter text: ";
                                    cin >> text;
                                    c.text = text;
                                    allSubs[i].posts[j].addComments(c);
                                }
                                catch (invalid_argument i)
                                {
                                    cout << i.what() << endl;
                                }
                                catch (logic_error l)
                                {
                                    cout << l.what() << endl;
                                }
                                
                            }

                            else
                            {
                            }
                        case 5:
                            cout << "Enter sharing method: ";
                            cin >> method;
                            cout << "Share successful" << endl;
                        case 6:
                            exit(0);
                        }
                }
            }
            else
            {}
        }
    }
    void explore()
    {
        string category;
        cout << "Categories: " << endl;
        cout << "1. Technology" << endl;
        cout << "2. Art" << endl;
        cout << "3. Fashion" << endl;
        cout << "4. DIY" << endl;
        cout << "5. Food" << endl;
        cout << "6. Gaming" << endl;
        cout << "7. Science" << endl;
        cout << "8. Funny" << endl;
        cout << "9. Sports" << endl;
        cout << "Enter category: ";
        cin >> category;
        for (int i = 0; i < allSubs.size(); i++)
        {
            if (allSubs[i].category == category)
            {
                for(int j = 0; j<= allSubs[i].count; j++)
                {
                    allSubs[i].posts[j].printDetails();
                    cout << endl;
                }
            }
        }
    }
    void chats()
    {
        cout << "redditUser1: Hi" << endl;
        cout << "ram123: Hello" << endl;
        cout << "sanju23: whatsup" << endl;
        cout << "You: Sorry this is reddit" << endl;
        cout << "You: Nice Joke" << endl;
    }
    void notifications()
    {
        cout << "Recommened: r/Lifehacks" << endl;
        cout << "IPL 2022 : Semis to go on today " << endl;
        cout << "Recommened : r/memelife" << endl;
    }
};

class Login
{
    static Login *instance;
    bool login;
    Login() : login(false)
    {
    }

public:
    static Login *getInstance()
    {
        if (!instance)
            instance = new Login;
        return instance;
    }
    bool getData()
    {
        return this->login;
    }
    bool setData(bool login)
    {
        this->login = login;
    }
};

Login *Login ::instance = 0;

int main()
{
    User u1("u", "female", 100, 45, 0, false, "i");
    User u2("u/Abhishek23", "male", 15, 90, 1000, true, "hi456");
    User u3("u/Abhi11", "male", 13, 80, 760, false, "ironman1");
    allUsers.push_back(u1);
    allUsers.push_back(u2);
    allUsers.push_back(u3);

    Moderator m1("Bhavani", "female", 75, 450, 1023, true, "iam1");
    Moderator m2("Bharath", "male", 50, 300, 850, true, "india1");

    SubReddit sr1("r/Damnthatsinteresting", "The most intresting place on reddit", "Technology", 5040219);
    SubReddit sr2("r/wow", "World of Warcraft on Reddit", "Art", 2204672);
    SubReddit sr3("r/FashionReps", "Largest Community for the disscussion of replica apparel", "Fashion", 7713777);
    SubReddit sr4("r/DIYclothes", "For all you fans ripped up clothes,tideye,homemade,sweaters", "DIY", 10164);
    SubReddit sr5("r/fastfood", "fastfood is for news,reviews and disscussion of fast food", "Food", 202016);
    SubReddit sr6("r/truegaming", "Subreddit dedicated for meaningful,insightful discussion on gaming topics", "Gaming", 1194284);
    SubReddit sr7("r/coumputerscience", "Subreddit dedicated to topics like algorithms,compution,theory of languages", "Science", 232223);
    SubReddit sr8("r/jokes", "The funniest sun on reddit", "Funny", 23119922);
    SubReddit sr9("r/Sport_women", "Women playing sports of all kind", "Sports", 13007);

    allSubs.push_back(sr1);
    allSubs.push_back(sr2);
    allSubs.push_back(sr3);
    allSubs.push_back(sr4);
    allSubs.push_back(sr5);
    allSubs.push_back(sr6);
    allSubs.push_back(sr7);
    allSubs.push_back(sr8);
    allSubs.push_back(sr9);

    Post p1(1, "Venture Beat", "VentureBeat is one of the leading tech blogs for transformative tech events and news.", 0, 0);
    Post p2(13, "Warcraft1", "", 0, 105);
    Post p3(21, "Fashion Quotes", "It's one thing to buy clothes that are in fashion because you like them.", 0, 0);
    Post p4(31, "DIYTshrits", "", 1011, 0);
    Post p5(41, "Speed of service", "Fast food is a type of mass-produced food designed for commercial resale and with a strong priority placed on speed of service", 0, 0);
    Post p6(53, "OnlineGamers", "", 1018, 0);
    Post p7(58, "WorldOfScience", "", 0, 118);
    Post p8(62, "FunnyWorld", "I walk around like everything’s fine, but deep down, inside my shoe, my sock is sliding off.", 0, 0);
    Post p9(68, "SportUpdate", "", 1022, 0);

    allPosts.push_back(p1);
    allPosts.push_back(p2);
    allPosts.push_back(p3);
    allPosts.push_back(p4);
    allPosts.push_back(p5);
    allPosts.push_back(p6);
    allPosts.push_back(p7);
    allPosts.push_back(p8);
    allPosts.push_back(p9);
    
    AddPost ap;
    ap.postText(sr1, p1);
    ap.postVideo(sr2, p2);
    ap.postText(sr3, p3);
    ap.postImage(sr4, p4);
    ap.postText(sr5, p5);
    ap.postImage(sr6, p6);
    ap.postVideo(sr7, p7);
    ap.postText(sr8, p8);
    ap.postImage(sr9, p9);

    Login *l = l->getInstance();

    int i, j, choice, ch, ch1, members, id, postId;
    Features f;
    string name, pw, u, g, title, text, about, category;
    User newUser;
    SubReddit s;
    MyException me;
    Post p;
    while (1)
    {
        cout << "\nREDDIT" << endl
             << endl;
        cout << "1. Sign In" << endl;
        cout << "2. Login" << endl;
        cout << "3. Features" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter username: ";
            cin >> u;
            cout << "Enter gender: ";
            cin >> g;
            cout << "Create password: ";
            cin >> pw;
            newUser.userName = u;
            newUser.gender = g;
            newUser.password = pw;
            allUsers.push_back(newUser);
            l->setData(true);
            cout << "\nDisplaying features: " << endl;
            f.displayFeatures();
            break;

        case 2:
            cout << "Enter user name: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> pw;
            for (i = 0; i < allUsers.size(); i++)
            {
                if (allUsers[i].userName == name && allUsers[i].password == pw)
                {
                    l->setData(true);
                    cout << "1. Create Subreddit" << endl;
                    cout << "2. Add post" << endl;
                    cout << "3. Features" << endl;
                    cout << "4. Exit" << endl;
                    cout << "Enter choice: ";
                    cin >> ch;
                    if (ch == 1)
                    {
                        try
                        {
                            me.checkKarma(allUsers[i]);
                            cout << "Enter subreddit name: ";
                            cin >> name;
                            cout << "Enter about: ";
                            cin >> about;
                            cout << "Enter category: ";
                            cin >> category;
                            s.name = name;
                            s.about = about;
                            s.category = category;
                            s.members = 0;
                            allUsers[i].joinSubreddit(s);
                            allSubs.push_back(s);
                        }
                        catch (out_of_range o)
                        {
                            cout << o.what() << endl;
                            ;
                        }
                    }
                    else if (ch == 2)
                    {
                        try
                        {
                            me.checkKarma(allUsers[i]);
                            cout << "Post types:" << endl;
                            cout << "1. Text" << endl;
                            cout << "2. Image" << endl;
                            cout << "3. Video" << endl;
                            cout << "Enter choice: ";
                            cin >> ch1;
                            if (ch1 == 1)
                            {
                                cout << "Enter subreddit name: ";
                                cin >> name;
                                for (j = 0; j < 10; j++)
                                {
                                    if (allSubs[j].name == name)
                                    {
                                        try
                                        {
                                        id = me.getId();
                                        cout << "Enter title: ";
                                        cin >> title;
                                        cout << "Enter text: ";
                                        cin >> text;
                                        p.postId = id;
                                        p.postTitle = title;
                                        p.text = text;
                                        ap.postText(allSubs[j], p);
                                        allSubs[j].count++;
                                        allPosts.push_back(p);
                                        }
                                        catch (invalid_argument i)
                                        {
                                            cout << i.what() << endl;
                                        }
                                        catch (logic_error l)
                                        {
                                            cout << l.what() << endl;
                                        }
                                    }
                                }
                            }
                            else if (ch1 == 2)
                            {
                                cout << "Enter subreddit name: ";
                                cin >> name;
                                for (j = 0; j < 10; j++)
                                {
                                    if (allSubs[j].name == name)
                                    {
                                        try
                                        {
                                            id = me.getId();
                                            cout << "Enter title: ";
                                            cin >> title;
                                            cout << "Enter Image id: ";
                                            cin >> postId;
                                            p.postId = id;
                                            p.postTitle = title;
                                            p.imageId = postId;
                                            ap.postImage(allSubs[j], p);
                                            allSubs[j].count++;
                                            allPosts.push_back(p);
                                        }
                                        catch (invalid_argument i)
                                        {
                                            cout << i.what() << endl;
                                        }
                                        catch (logic_error l)
                                        {
                                            cout << l.what() << endl;
                                        }
                                    }
                                }
                            }
                            else if (ch1 == 3)
                            {
                                cout << "Enter subreddit name: ";
                                cin >> name;
                                for (j = 0; j < 10; j++)
                                {
                                    if (allSubs[j].name == name)
                                    {
                                        try
                                        {
                                            id = me.getId();
                                            cout << "Enter title: ";
                                            cin >> title;
                                            cout << "Enter Video id: ";
                                            cin >> postId;
                                            p.postId = id;
                                            p.postTitle = title;
                                            p.imageId = postId;
                                            ap.postVideo(allSubs[j], p);
                                            allSubs[j].count++;
                                            allPosts.push_back(p);
                                        }
                                        catch (invalid_argument i)
                                        {
                                            cout << i.what() << endl;
                                        }
                                        catch (logic_error l)
                                        {
                                            cout << l.what() << endl;
                                        }
                                    }
                                }
                            }
                            else
                                cout << "Invalid" << endl;
                        }
                        catch (out_of_range o)
                        {
                            cout << o.what() << endl;
                        }
                    }

                    else if (ch == 3)
                        f.displayFeatures();

                    else
                    {
                    }
                }
            }
            break;

        case 3:
            if (l->getData() == true)
                f.displayFeatures();
            else
                cout << "You need to sign in or login first" << endl;
            break;

        case 4:
            exit(0);
        }
    }
    return 0;
}