#include "queue.hh"
#include <iostream>

using namespace std;

Queue::Queue(unsigned int cycle):
    cycle_(cycle)
{
}

Queue::~Queue()
{

}

void Queue::enqueue(const string &reg)
{
    if (is_green_) {
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
        return;
    }

    Vehicle *new_vehicle = new Vehicle;
    new_vehicle->reg_num = reg;

    if (first_ == nullptr) {
        first_ = new_vehicle;
        last_ = new_vehicle;
    } else {
        last_->next = new_vehicle;
        last_ = new_vehicle;
        last_->next = nullptr;
    }
}

void Queue::switch_light()
{
    is_green_ = !is_green_;

    if (is_green_ && first_ == nullptr) {
        cout << "GREEN: No vehicles waiting in traffic lights" << endl;
    } else if (!is_green_ && first_ == nullptr) {
        cout << "RED: No vehicles waiting in traffic lights" << endl;
    } else {
        unsigned int i = 1;

        cout <<  "GREEN: Vehicle(s) ";
        while (i <= cycle_) {
            dequeue();
            i++;
        } cout << "can go on" << endl;

        is_green_ = false;
    }
}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print() const
{
    if (is_green_) {
        if (first_ == nullptr) {
            cout << "GREEN: No vehicles waiting in traffic lights" << endl;
        } else {
            Vehicle *current_vehicle = first_;
            unsigned int i = 1;

            cout << "GREEN: Vehicle(s) ";
            while (current_vehicle != nullptr && i <= cycle_) {
                cout << current_vehicle->reg_num << " ";
                current_vehicle = current_vehicle->next;
                i++;
            } cout << "can go on" << endl;
        }

    }
    else if (!is_green_) {
        if (first_ == nullptr) {
            cout << "RED: No vehicles waiting in traffic lights" << endl;
        } else {
            Vehicle *current_vehicle = first_;

            cout << "RED: Vehicle(s) ";
            while (current_vehicle != nullptr) {
                cout << current_vehicle->reg_num << " ";
                current_vehicle = current_vehicle->next;
            } cout << "waiting in traffic lights" << endl;
        }
    }
}

void Queue::dequeue()
{
    if (first_ == nullptr) {
        return;
    } else {
        Vehicle *temp = first_;
        first_ = first_->next;
        cout << temp->reg_num << " ";
        delete temp;
    }
}
