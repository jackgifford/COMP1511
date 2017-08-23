def isValidDate(firstDay, firstMonth, firstHour, secondDay, secondMonth, secondHour):
    isSecondAfterFirst = False
    if secondMonth > firstMonth: 
        isSecondAfterFirst = True
    else if secondMonth == firstMonth:
        if secondDay == firstDay:
            if secondHour >= firstHour:
                isSecondAfterFirst = True
        else if secondDay > firstDay:
            isSecondAfterFirst = True
    else:
        isSecondAfterFirst = False

    return isSecondAfterFirst

def main():
    print(isValidDate(1,1,0, 2,2, 10))

if __name__ == '__main__':
    main()
