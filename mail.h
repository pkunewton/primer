//
// Created by Administrator on 2018/1/22.
//

#ifndef PRIMER_MAIL_H
#define PRIMER_MAIL_H

#include <string>
#include <set>

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Folder;
public:
    explicit Message(const std::string &str = ""):
        content(str) { };
    Message(const Message&);
    Message &operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void print_debug();
private:
    std::string content;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFolder(Folder *f) { folders.insert(f); };
    void removeFolder(Folder *f) { folders.erase(f); };
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Message;
public:
    Folder();
    Folder(const Folder&);
    Folder &operator=(const Folder&);
    ~Folder();

    void print_debug();
private:
    std::set<Message*> messages;
    void add_to_Message(const Folder&);
    void remove_from_Message();

    void addMsg(Message *m) { messages.insert(m) ;};
    void removeMsg(Message *m) { messages.erase(m); };
};

void swap(Folder&, Folder&);

#endif //PRIMER_MAIL_H
