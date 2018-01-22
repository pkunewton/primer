//
// Created by Administrator on 2018/1/22.
//
#include "mail.h"

Message::Message(const Message &m):
        content(m.content), folders(m.folders) {
    add_to_Folders(m);
}

Message& Message::operator=(const Message &m) {
    remove_from_Folders();
    content = m.content;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

void Message::save(Folder &folder) {
    folders.insert(&folder);
    folder.addMsg(this);
}

void Message::remove(Folder &folder) {
    folders.erase(&folder);
    folder.removeMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for(auto f : m.folders){
        f->addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for(auto f : folders){
        f->removeMsg(this);
    }
}
void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for(auto f : lhs.folders){
        f->removeMsg(&lhs);
    }
    for(auto f : rhs.folders){
        f->removeMsg(&rhs);
    }
    swap(lhs.content, rhs.content);
    swap(lhs.folders, rhs.folders);
    for(auto f : lhs.folders){
        f->addMsg(&lhs);
    }
    for(auto f : rhs.folders){
        f->addMsg(&rhs);
    }
}

Folder::Folder(const Folder &f):
        messages(f.messages){
    add_to_Message(f);
}

Folder& Folder::operator=(const Folder &f) {
    remove_from_Message();
    messages = f.messages;
    add_to_Message(f);
    return *this;
}

Folder::~Folder() {
    remove_from_Message();
}

void Folder::add_to_Message(const Folder &f) {
    for(auto m : f.messages){
        m->addFolder(this);
    }
}

void Folder::remove_from_Message() {
    for(auto m : messages){
        m->removeFolder(this);
    }
}

void swap(Folder &lhs, Folder &rhs) {
    for(auto m : lhs.messages){
        m->removeFolder(&lhs);
    }
    for(auto m : rhs.messages) {
        m->removeFolder(&rhs);
    }
    swap(lhs.messages, rhs.messages);
    for(auto m : lhs.messages) {
        m->addFolder(&lhs);
    }
    for(auto m : rhs.messages) {
        m->addFolder(&rhs);
    }
}
