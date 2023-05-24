#include <gtest/gtest.h>
#include "func_for_test.h"

// Тесты для класса Task
TEST(TaskTest, Constructor) {
    Task task("Test Task");
    EXPECT_EQ(task.name, "Test Task");
    EXPECT_FALSE(task.is_done);
}

// Тесты для класса ToDoList
TEST(ToDoListTest, AddTask) {
    ToDoList todo;
    Task task("Test Task");
    todo.add_task(task);
    EXPECT_EQ(todo.tasks.size(), 1);
    EXPECT_EQ(todo.tasks[0].name, "Test Task");
    EXPECT_FALSE(todo.tasks[0].is_done);
}

TEST(ToDoListTest, MarkTaskDone) {
    ToDoList todo;
    Task task("Test Task");
    todo.add_task(task);
    todo.mark_task_done(0);
    EXPECT_TRUE(todo.tasks[0].is_done);
}

TEST(ToDoListTest, PrintTasksEmpty) {
    ToDoList todo;
    testing::internal::CaptureStdout();  // Захватываем вывод в консоль
    todo.print_tasks();
    std::string output = testing::internal::GetCapturedStdout();  // Получаем захваченный вывод
    EXPECT_EQ(output, "List of tasks is empty.\n");
}

TEST(ToDoListTest, PrintTasksNonEmpty) {
    ToDoList todo;
    Task task1("Task 1");
    Task task2("Task 2");
    todo.add_task(task1);
    todo.add_task(task2);
    testing::internal::CaptureStdout();
    todo.print_tasks();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List of tasks:\n0. Task 1\n1. Task 2\n");
}

TEST(ToDoListTest, EditTaskName) {
    ToDoList todo;
    Task task("Old Task Name");
    todo.add_task(task);
    todo.edit_task_name(0, "New Task Name");
    EXPECT_EQ(todo.tasks[0].name, "New Task Name");
}

TEST(ToDoListTest, EditTaskNameInvalidIndex) {
    ToDoList todo;
    testing::internal::CaptureStdout();
    todo.edit_task_name(0, "New Task Name");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "False number of task.\n");
}

TEST(ToDoListTest, MarkTaskUndone) {
    ToDoList todo;
    Task task("Test Task");
    todo.add_task(task);
    todo.mark_task_done(0);
    todo.mark_task_undone(0);
    EXPECT_FALSE(todo.tasks[0].is_done);
}

TEST(ToDoListTest, RemoveTask) {
    ToDoList todo;
    Task task("Test Task");
    todo.add_task(task);
    testing::internal::CaptureStdout();
    todo.remove_task(0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Task is removed.\n");
    EXPECT_EQ(todo.tasks.size(), 0);
}

TEST(ToDoListTest, RemoveTaskInvalidIndex) {
    ToDoList todo;
    testing::internal::CaptureStdout();
    todo.remove_task(0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "False number of task.\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
