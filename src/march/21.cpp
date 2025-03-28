#include <ranges>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace views = std::views;

class Solution {
public:
    // clang-format off
    constexpr auto findAllRecipes(std::vector<std::string>& recipes,
        std::vector<std::vector<std::string>>& ingredients,
        std::vector<std::string>& supplies)
    -> std::vector<std::string> {
        // clang-format on
        std::unordered_map<std::string, int> recipeM;
        for (const auto&& [idx, recipe]: views::enumerate(recipes)) {
            recipeM[recipe] = static_cast<int>(idx);
        }

        std::vector<std::string> res;
        std::unordered_set<std::string> availableSupplies(supplies.begin(), supplies.end());
        std::vector<int> visited(recipes.size(), 0);
        auto dfs = [&](int recipeIdx, auto&& dfs) -> bool {
            if (visited[recipeIdx] == 2) {
                return availableSupplies.contains(recipes[recipeIdx]);
            }
            if (visited[recipeIdx] == 1) {
                return false;
            }

            visited[recipeIdx] = 1;
            for (const auto& ing: ingredients[recipeIdx]) {
                if (availableSupplies.contains(ing)) {
                    continue;
                }
                if (auto it = recipeM.find(ing); it != recipeM.end()) {
                    if (!dfs(it->second, dfs)) {
                        visited[recipeIdx] = 2;
                        return false;
                    }
                } else {
                    visited[recipeIdx] = 2;
                    return false;
                }
            }

            availableSupplies.insert(recipes[recipeIdx]);
            visited[recipeIdx] = 2;
            return true;
        };

        for (const auto&& [idx, recipe]: views::enumerate(recipes)) {
            if (dfs(idx, dfs)) {
                res.push_back(recipes[idx]);
            }
        }

        return res;
    }
};
