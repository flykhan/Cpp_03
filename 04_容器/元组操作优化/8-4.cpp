#include <iostream>
#include <string>

#include "8-4.hpp"

int main()
{
    // 分别定义了两组列索引
    std::tuple<std::string, std::string> col_idx01("Id", "Grade");
    std::tuple<std::string, std::string> col_idx02("Name", "Age");
    // 将两组列索引合并
    auto new_col = std::tuple_cat(col_idx01, col_idx02);

    // 利用 make_tuple 创建元组(记录)
    auto student1 = std::make_tuple(1, 98.0, "张三", 18);
    auto student2 = std::make_tuple(2, 95.5, "李四", 19);

    // 打印列索引(表头)，利用了前面定义的 tuple_len 和 tuple_index
    for (int i = 0; i < tuple_len(new_col); ++i)
    {
        std::cout << tuple_index(new_col, i) << "\t";
    }
    std::cout << std::endl;

    // 打印记录
    for (int i = 0; i < tuple_len(student1); ++i)
    {
        std::cout << tuple_index(student1, i) << "\t";
    }
    std::cout << std::endl;

    for (int i = 0; i < tuple_len(student2); ++i)
    {
        std::cout << tuple_index(student2, i) << "\t";
    }
    std::cout << std::endl;

    return 0;
}