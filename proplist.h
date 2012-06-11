#include <boost/variant.hpp>
#include <string>
#include <map>
#include <stdexcept>

typedef std::string String;

class PropList
{
public:
    typedef boost::variant<int, char, String> Property;

    PropList() {}
    ~PropList() {}

    template <typename T>
    void add(const String & key, const T & val)
    {
        m_propertyMap.insert(std::make_pair(key, val));
    }

    template <typename T>
    const T & get(const String & key) const
    {
        PropertyMap::const_iterator it = m_propertyMap.find(key);
        if (it != m_propertyMap.end())
        {
            return boost::get<T>(it->second);
        }
        throw std::runtime_error("Invalid property name.");
    }

    template <typename T>
    const T & get(const String & key, const T & def) const
    {
        PropertyMap::const_iterator it = m_propertyMap.find(key);
        if (it != m_propertyMap.end())
        {
            return boost::get<T>(it->second);
        }
        else
        {
            return def;
        }
    }

private:
    typedef std::map<String, Property> PropertyMap;
    PropertyMap m_propertyMap;
};

