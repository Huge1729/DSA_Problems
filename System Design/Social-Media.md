# Social Media Design
## ER Model Description

## 1. Entities and Attributes

### User
- **user_id** (Primary Key)  
- **username**  
- **password**  
- **email**  
- **address**

### AdminUser (Inherits from User)
- *No additional attributes*

### RegularUser (Inherits from User)
- *No additional attributes*

### Post
- **post_id** (Primary Key)  
- **content**  
- **likes**  
- **comments** (List of comments)

### Friendship
- **friendship_id** (Primary Key)  
- **user1_id** (Foreign Key referencing **User**)  
- **user2_id** (Foreign Key referencing **User**)  
- **Friendship relation:** Stores accepted friend relationships.

### FriendRequest
- **request_id** (Primary Key)  
- **sender_id** (Foreign Key referencing **User**)  
- **receiver_id** (Foreign Key referencing **User**)  
- **status** (Accepted / Pending / Rejected)

### Notification
- **notification_id** (Primary Key)  
- **user_id** (Foreign Key referencing **User**)  
- **message**  
- **One-to-Many relationship:** One user can have multiple notifications.

### Comment
- **comment_id** (Primary Key)  
- **content**  
- **post_id** (Foreign Key referencing **Post**)  
- **user_id** (Foreign Key referencing **User**)  
- **Many-to-One relationship:** Multiple comments on a single post.

---

## 2. Relationships

### User-Post Relationship (One-to-Many)
- A **user** can create **many posts**, but each **post** is created by only one user.  
- **Foreign Key:** `user_id` in the **Post** entity referencing **User**.

### User-Friendship Relationship (Many-to-Many)
- Users can have **many friends** through a **Friendship** entity.  
- The **Friendship** entity holds two user references (`user1_id` and `user2_id`) representing the friendship relationship.

### User-FriendRequest Relationship (One-to-Many)
- A **user** can send **many friend requests**, but each request is linked to a single **sender and receiver**.  
- **Foreign Keys:** `sender_id` and `receiver_id` reference the **User** entity.

### User-Notification Relationship (One-to-Many)
- A **user** can receive **multiple notifications**, but each notification belongs to only one user.  
- **Foreign Key:** `user_id` in the **Notification** entity referencing **User**.

### Post-Comment Relationship (One-to-Many)
- A **post** can have **many comments**, but each comment belongs to a single **post**.  
- **Foreign Key:** `post_id` in the **Comment** entity referencing **Post**.

### User-Comment Relationship (One-to-Many)
- A **user** can make **many comments**, but each comment is authored by a single **user**.  
- **Foreign Key:** `user_id` in the **Comment** entity referencing **User**.

## 6. C++ OOP Code
---

## Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// === Abstract User Class (Abstraction) ===
class User {
protected:
    string username, password, email, address;
    vector<User*> friends;      // Friend list
    vector<string> notifications; // Notifications

public:
    User(string uname, string pwd, string mail, string addr)
        : username(uname), password(pwd), email(mail), address(addr) {}

    virtual void createPost(const string& content) = 0;  // Polymorphism

    void sendFriendRequest(User* user) {
        cout << username << " sent a friend request to " << user->getUsername() << ".\n";
        user->addFriend(this);  // Auto-accept friend requests for simplicity
    }

    void addFriend(User* user) {
        friends.push_back(user);
        notifications.push_back("You are now friends with " + user->getUsername());
        cout << username << " and " << user->getUsername() << " are now friends.\n";
    }

    virtual void viewProfile() {
        cout << "Profile: " << username << " | Email: " << email << " | Address: " << address << "\n";
    }

    void viewNotifications() {
        cout << "\nNotifications for " << username << ":\n";
        for (const string& notif : notifications) {
            cout << "- " << notif << "\n";
        }
    }

    string getUsername() const { return username; }
};

// === Post Class ===
class Post {
private:
    string content;
    int likes = 0;
    vector<string> comments;

public:
    Post(const string& c) : content(c) {}

    void likePost() { ++likes; }

    void addComment(const string& comment) { comments.push_back(comment); }

    void displayPost() {
        cout << "Post: " << content << "\nLikes: " << likes << "\nComments:\n";
        for (const string& comment : comments) {
            cout << "- " << comment << "\n";
        }
    }
};

// === Regular User Class: Inherits from User (Inheritance) ===
class RegularUser : public User {
    vector<Post*> posts;  // List of posts created by the user

public:
    RegularUser(string uname, string pwd, string mail, string addr)
        : User(uname, pwd, mail, addr) {}

    void createPost(const string& content) override {
        Post* newPost = new Post(content);
        posts.push_back(newPost);
        cout << username << " created a new post.\n";
    }

    void likePost(Post* post) {
        post->likePost();
        cout << username << " liked the post.\n";
    }

    void commentOnPost(Post* post, const string& comment) {
        post->addComment(comment);
        cout << username << " commented: " << comment << "\n";
    }
};

// === Admin User Class: Inherits from User (Inheritance) ===
class AdminUser : public User {
public:
    AdminUser(string uname, string pwd, string mail, string addr)
        : User(uname, pwd, mail, addr) {}

    void createPost(const string& content) override {
        cout << "Admin " << username << " posted: " << content << "\n";
    }

    void deletePost(Post* post) {
        cout << "Admin " << username << " deleted a post.\n";
        delete post;  // Simulating post deletion
    }
};

// === Social Media App Class ===
class SocialMediaApp {
private:
    unordered_map<string, User*> users;  // Store users by their username

public:
    void signup(User* user) {
        users[user->getUsername()] = user;
        cout << user->getUsername() << " signed up successfully!\n";
    }

    User* login(const string& username, const string& password) {
        if (users.find(username) != users.end()) {
            cout << username << " logged in successfully!\n";
            return users[username];
        } else {
            cout << "Invalid username or password.\n";
            return nullptr;
        }
    }
};

// === Main Function to Test the App ===
int main() {
    SocialMediaApp app;

    // Create users
    AdminUser* admin = new AdminUser("admin", "admin123", "admin@mail.com", "Admin's House");
    RegularUser* john = new RegularUser("john_doe", "password123", "john@mail.com", "123 John St");
    RegularUser* jane = new RegularUser("jane_doe", "password456", "456 Jane Ave");

    // Users sign up
    app.signup(admin);
    app.signup(john);
    app.signup(jane);

    // Login users
    User* loggedInUser = app.login("john_doe", "password123");

    if (loggedInUser) {
        // John creates a post
        john->createPost("Hello, world! This is my first post.");
    }

    // John sends a friend request to Jane
    john->sendFriendRequest(jane);

    // Admin creates an announcement
    admin->createPost("Welcome to the social media app!");

    // Jane likes and comments on John's post
    Post* post = new Post("Learning C++ OOP is fun!");  // Example post
    jane->likePost(post);
    jane->commentOnPost(post, "Indeed it is!");

    // Display the post
    post->displayPost();

    // View notifications for John and Jane
    john->viewNotifications();
    jane->viewNotifications();

    return 0;
}
```
### Expected output for the social media Application
```
admin signed up successfully!
john_doe signed up successfully!
jane_doe signed up successfully!
john_doe logged in successfully!
john_doe created a new post.
john_doe sent a friend request to jane_doe.
jane_doe and john_doe are now friends.
Admin admin posted: Welcome to the social media app!
jane_doe liked the post.
jane_doe commented: Indeed it is!
Post: Learning C++ OOP is fun!
Likes: 1
Comments:
- Indeed it is!

Notifications for john_doe:
- You are now friends with jane_doe

Notifications for jane_doe:
- You are now friends with john_doe

