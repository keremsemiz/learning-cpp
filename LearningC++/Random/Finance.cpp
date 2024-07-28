#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Asset {
private:
    std::string name;
    double value;
    std::string type;

public:
    Asset(const std::string& n, double v, const std::string& t) : name(n), value(v), type(t) {}

    std::string getName() const { return name; }
    double getValue() const { return value; }
    std::string getType() const { return type; }

    void display() const {
        std::cout << "Asset: " << name << ", Value: $" << value << ", Type: " << type << std::endl;
    }
};

class Portfolio {
private:
    std::string owner;
    std::vector<Asset> assets;

public:
    Portfolio(const std::string& ownerName) : owner(ownerName) {}

    void addAsset(const Asset& asset) {
        assets.push_back(asset);
    }

    void removeAsset(const std::string& assetName) {
        assets.erase(std::remove_if(assets.begin(), assets.end(), [&](const Asset& asset) {
            return asset.getName() == assetName;
        }), assets.end());
    }

    double calculateTotalValue() const {
        double total = 0.0;
        for (const auto& asset : assets) {
            total += asset.getValue();
        }
        return total;
    }

    void displayAssets() const {
        std::cout << "Portfolio of " << owner << ":\n";
        for (const auto& asset : assets) {
            asset.display();
        }
        std::cout << "Total Value: $" << calculateTotalValue() << std::endl;
    }
};

class PortfolioManager {
private:
    std::vector<Portfolio> portfolios;

public:
    void addPortfolio(const std::string& ownerName) {
        portfolios.emplace_back(ownerName);
    }

    void addAssetToPortfolio(const std::string& ownerName, const Asset& asset) {
        auto it = std::find_if(portfolios.begin(), portfolios.end(), [&](const Portfolio& portfolio) {
            return portfolio.getOwner() == ownerName;
        });

        if (it != portfolios.end()) {
            it->addAsset(asset);
        } else {
            std::cout << "Portfolio not found." << std::endl;
        }
    }

    void removeAssetFromPortfolio(const std::string& ownerName, const std::string& assetName) {
        auto it = std::find_if(portfolios.begin(), portfolios.end(), [&](const Portfolio& portfolio) {
            return portfolio.getOwner() == ownerName;
        });

        if (it != portfolios.end()) {
            it->removeAsset(assetName);
        } else {
            std::cout << "Portfolio not found." << std::endl;
        }
    }

    void displayPortfolio(const std::string& ownerName) const {
        auto it = std::find_if(portfolios.begin(), portfolios.end(), [&](const Portfolio& portfolio) {
            return portfolio.getOwner() == ownerName;
        });

        if (it != portfolios.end()) {
            it->displayAssets();
        } else {
            std::cout << "Portfolio not found." << std::endl;
        }
    }
};

int main() {
    PortfolioManager manager;

    manager.addPortfolio("John Doe");
    manager.addPortfolio("Jane Smith");

    manager.addAssetToPortfolio("John Doe", Asset("AAPL", 150.0, "Stock"));
    manager.addAssetToPortfolio("John Doe", Asset("GOOGL", 200.0, "Stock"));
    manager.addAssetToPortfolio("Jane Smith", Asset("US Treasury Bond", 1000.0, "Bond"));

    std::cout << "John Doe's Portfolio:\n";
    manager.displayPortfolio("John Doe");

    std::cout << "\nJane Smith's Portfolio:\n";
    manager.displayPortfolio("Jane Smith");

    std::cout << "\nRemoving GOOGL from John Doe's Portfolio...\n";
    manager.removeAssetFromPortfolio("John Doe", "GOOGL");

    std::cout << "\nJohn Doe's Portfolio:\n";
    manager.displayPortfolio("John Doe");

    return 0;
}
