#include "app.hpp"
#include "imgui.h"
#include "person.hpp"
#include "personDb.hpp"
#include <cstdio>
#include <iostream>

App::App() {
    database = PersonDb();
}

typedef enum ValidationError {
    VAL_NONE,
    VAL_NEG_AGE,
    VAL_NAME_SHORT
} ValidationError;

bool validateAgePositive(int age) {
    return age >= 0;
}

bool validateNameLength(std::string& name) {
    int characters = 0;
    for(int i = 0; i < 3; i++) {
        if(name[i] == '\0') return false;
    }
    return true;
}

void App::draw() {
    if(ImGui::Begin("Database")) {
        ImGui::BeginChild("t");
        database.draw();
        ImGui::EndChild();
        if(ImGui::Button("Add person")) {
            ImGui::OpenPopup("Add person");
            tmpPerson = Person();
        }

        if(ImGui::BeginPopupModal("Add person", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
            int err = 0;
            ImGui::InputText("Name", &tmpPerson.name[0], tmpPerson.name.size());
            bool val_err = !validateNameLength(tmpPerson.name);
            err += val_err;
            ImGui::Text(val_err ? "Name length should be at least 3 characters!" : "");
            val_err = !validateAgePositive(tmpPerson.age);
            err += val_err;
            ImGui::InputInt("Age", &tmpPerson.age, 1, 10);
            ImGui::Text(val_err ? "Age cannot be negative!" : "");
            if(err) ImGui::BeginDisabled();
            if(ImGui::Button("Add")) {
                database.add(tmpPerson);
                ImGui::CloseCurrentPopup();
            }
            if(err) ImGui::EndDisabled();
            ImGui::SameLine();
            if(ImGui::Button("Cancel")) {
                ImGui::CloseCurrentPopup();
            }

            if(ImGui::BeginPopupModal("Error!", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {

                switch (err) {
                    case VAL_NEG_AGE:
                        ImGui::Text("Age cannot be negative!");
                        break;
                    case VAL_NAME_SHORT:
                        ImGui::Text("Name length should be at least 3 characters!");
                    default:
                        ImGui::Text("Unknown error!");
                }
                if(ImGui::Button("OK")) {
                    ImGui::CloseCurrentPopup();
                }
                ImGui::EndPopup();
            }

            ImGui::EndPopup();
        }


    }
    ImGui::End();
}
