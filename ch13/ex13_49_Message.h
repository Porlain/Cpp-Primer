/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-29 14:51:18
 */
#ifndef CP5_MESSAGE_H_
#define CP5_MESSAGE_H_
#include <string>
#include <set>

class Folder;

class Message
{
public:
    friend class Folder;
    friend void swap(Message &, Message &);

public:
    explicit Message(const std::string &m = "") : contents(m) {}
    Message(const Message &);
    Message &operator=(const Message &);
    Message(Message &&);            // need to update the Folders
    Message &operator=(Message &&); // need to update the Folders

    void save(Folder &);
    void remove(Folder &);

    ~Message();

private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }

    void move_Folders(Message *); // define function to do the common work
};

void swap(Message &, Message &);

class Folder
{
public:
    friend void swap(Folder &, Folder &);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    Folder(Folder &&);            // need to update the Messages
    Folder &operator=(Folder &&); // need to update the Messages
    ~Folder();

private:
    std::set<Message *> msgs;
    void add_to_Message(const Folder &);
    void remove_from_Message();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }

    void move_Messages(Folder *); // define function to do the common work
};

void swap(Folder &, Folder &);

#endif