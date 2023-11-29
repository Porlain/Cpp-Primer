/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-28 10:26:55
 */
#include "ex13_34.h"
#include <iostream>

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    lhs.remove_from_Folders(); // Use existing member function to avoid duplicate code.
    rhs.remove_from_Folders(); // Use existing member function to avoid duplicate code.

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    lhs.add_to_Folders(lhs); // Use existing member function to avoid duplicate code.
    rhs.add_to_Folders(rhs); // Use existing member function to avoid duplicate code.
}

Message::Message(const Message &m)
{
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::save(Folder &f)
{
    addFldr(&f); // Use existing member function to avoid duplicate code.
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    remFldr(&f); // Use existing member function to avoid duplicate code.
    f.remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;

    lhs.remove_from_Message();
    rhs.remove_from_Message();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_to_Message(lhs);
    rhs.add_to_Message(rhs);
}

Folder::Folder(const Folder &f) : msgs(f.msgs) { add_to_Message(f); }

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_Message();
    msgs = rhs.msgs;
    add_to_Message(rhs);
    return *this;
}

Folder::~Folder()
{
    remove_from_Message();
}

void Folder::add_to_Message(const Folder &f)
{
    for (auto m : f.msgs)
        m->addFldr(this);
}

void Folder::remove_from_Message(){
    for (auto m : msgs)
        m->remFldr(this);
}
