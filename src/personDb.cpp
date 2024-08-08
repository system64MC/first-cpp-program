#include "imgui.h"
#include "person.hpp"
#include <stdexcept>
#include <vector>
#include "personDb.hpp"

PersonDb::PersonDb() {
    list = std::vector<Person>();
}

void PersonDb::add(Person& person) {
    list.push_back(person);
}

void PersonDb::draw() {
    if(ImGui::BeginTable("db", 2)) {
        ImGui::TableSetupColumn("Name");
        ImGui::TableSetupColumn("Age");
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();
        for(int i = 0; i < list.size(); i++) {
            ImGui::TableSetColumnIndex(0);
            ImGui::Text(list[i].name.c_str());
            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%d", list[i].age);
            ImGui::TableNextRow();
        }

        ImGui::EndTable();
    }
}
