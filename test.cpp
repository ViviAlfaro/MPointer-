#include <gtest/gtest.h>
#include "MPointer.h"
#include "LinkedList.h"

// Pruebas para MPointer
TEST(MPointerTest, DefaultConstructor) {
    MPointer<int> ptr;
    EXPECT_NE(ptr.operator->(), nullptr); 
    EXPECT_EQ(*ptr, 0); // Usar operador * para acceder al valor
}

TEST(MPointerTest, SetValue) {
    MPointer<int> ptr;
    ptr.setValue(10);
    EXPECT_EQ(*ptr, 10); // Usar operador * para acceder al valor
}

TEST(MPointerTest, CopyConstructor) {
    MPointer<int> ptr1;
    ptr1.setValue(20);
    MPointer<int> ptr2(ptr1);
    EXPECT_EQ(*ptr2, 20); // Usar operador * para acceder al valor
}

TEST(MPointerTest, AssignmentOperator) {
    MPointer<int> ptr1;
    ptr1.setValue(30);
    MPointer<int> ptr2;
    ptr2 = ptr1;
    EXPECT_EQ(*ptr2, 30); // Usar operador * para acceder al valor
}

// Pruebas para LinkedList
TEST(LinkedListTest, AddAndDisplay) {
    LinkedList<int> list;
    list.add(10);
    list.add(20);
    list.add(30);

    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20 30 \n");
}

TEST(LinkedListTest, QuickSort) {
    LinkedList<int> list;
    list.add(30);
    list.add(10);
    list.add(20);

    list.quickSort();
    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20 30 \n");
}

TEST(LinkedListTest, BubbleSort) {
    LinkedList<int> list;
    list.add(30);
    list.add(10);
    list.add(20);

    list.bubbleSort();
    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20 30 \n");
}

TEST(LinkedListTest, InsertionSort) {
    LinkedList<int> list;
    list.add(30);
    list.add(10);
    list.add(20);

    list.insertionSort();
    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20 30 \n");
}

TEST(LinkedListTest, RemoveElement) {
    LinkedList<int> list;
    list.add(10);
    list.add(20);
    list.add(30);

    list.remove(20); // 
    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 30 \n");
}

// lista esté vacía después de eliminar todos los elementos
TEST(LinkedListTest, RemoveAllElements) {
    LinkedList<int> list;
    list.add(10);
    list.add(20);
    list.add(30);

    list.remove(10);
    list.remove(20);
    list.remove(30);

    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
