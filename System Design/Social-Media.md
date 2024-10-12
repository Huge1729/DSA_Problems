# Social Media Design

## 1. Identifying Entities
Entities represent real-world objects or concepts, and in the given code, each class will serve as an entity:
- **User** (with subclasses `AdminUser` and `RegularUser` for polymorphism)
- **Roles**
- **Permission**
- **Friends**
- **Photos**
- **Post**
- **Shares**

## 2. Attributes for Each Entity
Each class in the code has certain attributes, which we will define as the entity's properties.

### User Entity
- `user_id` (Primary Key)
- `user_name`
- `user_mobile`
- `user_email`
- `user_address`
- `login_username`
- `login_password`

### Roles Entity
- `role_id` (Primary Key)
- `role_name`
- `role_desc`

### Permission Entity
- `perm_id` (Primary Key)
- `perm_name`

### Friends Entity
- `friend_id` (Primary Key)
- `friend_name`
- `friend_add`
- `friend_username`

### Photos Entity
- `photo_id` (Primary Key)
- `photo_type`
- `photo_size`
- `photo_desc`
- `photo_name`

### Post Entity
- `post_id` (Primary Key)
- `post_desc`
- `post_type`

### Shares Entity
- `share_id` (Primary Key)
- `share_name`
- `share_desc`
- `share_type`

## 3. Relationships
The relationships between the entities are defined through their associations in the code.

### User and Roles
- **Relationship:** A user can have multiple roles.
- **Type:** One-to-Many (A user can have many roles, but a role can belong to many users).
- **Associative Entity:** User_Roles (This is a many-to-many relationship that can be modeled through an associative table).
- **Attributes in User_Roles:** `user_id` (Foreign Key), `role_id` (Foreign Key)

### Roles and Permission
- **Relationship:** A role can have multiple permissions.
- **Type:** One-to-Many (A role can have many permissions, but a permission can belong to many roles).
- **Associative Entity:** Role_Permissions
- **Attributes in Role_Permissions:** `role_id` (Foreign Key), `perm_id` (Foreign Key)

### User and Friends
- **Relationship:** A user can have multiple friends.
- **Type:** One-to-Many (A user can have many friends).
- **Associative Entity:** User_Friends
- **Attributes in User_Friends:** `user_id` (Foreign Key), `friend_id` (Foreign Key)

### User and Photos
- **Relationship:** A user can upload multiple photos.
- **Type:** One-to-Many (A user can have many photos).
- **Associative Entity:** User_Photos
- **Attributes in User_Photos:** `user_id` (Foreign Key), `photo_id` (Foreign Key)

### User and Post
- **Relationship:** A user can make multiple posts.
- **Type:** One-to-Many (A user can create many posts).
- **Associative Entity:** User_Posts
- **Attributes in User_Posts:** `user_id` (Foreign Key), `post_id` (Foreign Key)

### User and Shares
- **Relationship:** A user can share multiple posts.
- **Type:** One-to-Many (A user can share many posts).
- **Associative Entity:** User_Shares
- **Attributes in User_Shares:** `user_id` (Foreign Key), `share_id` (Foreign Key)

## 4. Constraints
Constraints help to ensure data integrity, and they are derived from the relationships and attributes.
- **Primary Keys:** Unique identifiers for each entity (e.g., `user_id`, `role_id`, `perm_id`, `friend_id`, `photo_id`, etc.)
- **Foreign Keys:** Used in associative entities to relate two tables (e.g., `user_id` in User_Roles, `role_id` in Role_Permissions).
- **Not Null:** Attributes like `user_name`, `user_email`, etc., should be constrained as Not Null to ensure the user must provide valid data.
- **Unique Constraints:** Certain fields such as `login_username` and `user_email` must be unique to prevent duplication.

## 5. Cardinality
- **User and Roles:** Many-to-Many (A user can have multiple roles, and a role can be assigned to multiple users).
- **Roles and Permission:** Many-to-Many (A role can have multiple permissions, and a permission can belong to multiple roles).
- **User and Friends:** One-to-Many (A user can have many friends, but a friend relationship is unique to each user).
- **User and Photos:** One-to-Many (A user can upload many photos).
- **User and Post:** One-to-Many (A user can create many posts).
- **User and Shares:** One-to-Many (A user can share many posts).

## 6. C++ OOP Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward declarations
class Permission;
class Roles;
class Photos;
class Post;
class Shares;
class Friends;

// Base User class (with inheritance for AdminUser and RegularUser)
class User {
public:
    int user_id;
    string user_name;
    string user_mobile;
    string user_email;
    string user_address;
    // Constructor for User
    User(int id, string name, string mobile, string email, string address)
        : user_id(id), user_name(name), user_mobile(mobile), user_email(email), user_address(address) {}
    // Function to associate login credentials
    void setLogin(string username, string password) {
        login_username = username;
        login_password = password;
    }

    virtual void addRole(Roles* role);    // Virtual for possible overriding
    virtual void makePost(Post* post);    // Virtual for possible overriding
    virtual void managePhotos(Photos* photo);
    virtual void manageFriend(Friends* friend_obj);
protected:
    string login_username;
    string login_password;
    vector<Roles*> roles;     // Composition with Roles
    vector<Photos*> photos;   // Composition with Photos
    vector<Post*> posts;      // Composition with Post
    vector<Friends*> friends; // Composition with Friends
};

// Derived AdminUser class (inherits from User)
class AdminUser : public User {
public:
    AdminUser(int id, string name, string mobile, string email, string address)
        : User(id, name, mobile, email, address) {}
    // Admin-specific functionality to manage all users
    void manageUsers(vector<User*>& all_users) {
        cout << "Admin " << user_name << " managing users...\n";
        for (User* user : all_users) {
            cout << "User: " << user->user_name << " (" << user->user_email << ")\n";
        }
    }

    // Override the makePost function for admin-specific posts
    void makePost(Post* post) override {
        posts.push_back(post);
        cout << "Admin-specific post created by " << user_name << "\n";
    }
};

// Derived RegularUser class (inherits from User)
class RegularUser : public User {
public:
    RegularUser(int id, string name, string mobile, string email, string address)
        : User(id, name, mobile, email, address) {}

    // Regular user post method
    void makePost(Post* post) override {
        posts.push_back(post);
        cout << "Regular user " << user_name << " created a post.\n";
    }
};

// Roles Class
class Roles {
public:
    int role_id;
    string role_name;
    string role_desc;
    vector<Permission*> permissions;  // Association with Permission
    Roles(int id, string name, string desc) : role_id(id), role_name(name), role_desc(desc) {}

    void addPermission(Permission* permission) {
        permissions.push_back(permission);
    }
};

// Permission Class
class Permission {
public:
    int perm_id;
    string perm_name;

    Permission(int id, string name) : perm_id(id), perm_name(name) {}
};

// Friends Class
class Friends {
public:
    int friend_id;
    string friend_name;
    string friend_add;
    string friend_username;

    Friends(int id, string name, string add, string username)
        : friend_id(id), friend_name(name), friend_add(add), friend_username(username) {}
};

// Photos Class
class Photos {
public:
    int photo_id;
    string photo_type;
    string photo_size;
    string photo_desc;
    string photo_name;

    Photos(int id, string type, string size, string desc, string name)
        : photo_id(id), photo_type(type), photo_size(size), photo_desc(desc), photo_name(name) {}
};

// Post Class
class Post {
public:
    int post_id;
    string post_desc;
    string post_type;

    Post(int id, string desc, string type) : post_id(id), post_desc(desc), post_type(type) {}
};

// Shares Class
class Shares {
public:
    int share_id;
    string share_name;
    string share_desc;
    string share_type;

    Shares(int id, string name, string desc, string type)
        : share_id(id), share_name(name), share_desc(desc), share_type(type) {}
};

// Implementing functions for User class
void User::addRole(Roles* role) {
    roles.push_back(role);
}

void User::managePhotos(Photos* photo) {
    photos.push_back(photo);
}

void User::manageFriend(Friends* friend_obj) {
    friends.push_back(friend_obj);
}

int main() {
    // Example usage
    AdminUser admin(1, "Admin User", "1234567890", "admin@example.com", "Admin Address");
    RegularUser user(2, "Regular User", "0987654321", "user@example.com", "User Address");

    // Create roles and permissions
    Roles adminRole(1, "Administrator", "Can manage users and content");
    Permission perm1(1, "Create Post");

    adminRole.addPermission(&perm1);
    admin.addRole(&adminRole);

    // Creating a post
    Post post1(1, "Hello, this is my first post!", "text");
    user.makePost(&post1);

    // Admin managing users
    admin.manageUsers({ &user });

    return 0;
}
