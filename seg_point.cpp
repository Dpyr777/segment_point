#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;

std::vector <int> get_covering_set(std::vector <Segment> segments)
{
    std::sort(segments.begin(), segments.end(),[] (Segment seg1 , Segment seg2) -> bool { return seg1.second < seg2.second; });
    std::vector <int> result;
    int temp{};

    for (auto & seg : segments)
    {
        if (seg.first > temp)
        {
            temp = seg.second;
            result.push_back(temp);
        }
    }
            
    return result;
}

int main()
{
    int segments_count;
    std::cin >> segments_count;
    std::vector <Segment> segments(segments_count);
    for (auto &s : segments)
    {
        std::cin >> s.first >> s.second;
    }

    auto points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point : points)
    {
        std::cout << point << " ";
    }
    std::cout << std::endl;
    return 0;
}
