#ifndef THROWABLE_H
#define THROWABLE_H

class Throwable
{
public:
    [[nodiscard]] bool isThrown() const;

    virtual void endThrown();

    virtual void startThrown();

private:
    bool thrown{};
};

#endif // THROWABLE_H
