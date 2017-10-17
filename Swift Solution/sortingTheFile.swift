import Foundation


// Input variables you can change those variables
var file = "hs-set-10k.txt"
var isMergeSort = true
var isFullSort = true
var outputFileName = "hs-set-10k-out.txt"
var sortedArray = Array<(name: String, className: String, rarity: String, set: String, type: String, cost: String)>()
// Struct for cards
var cards = Array<(name: String, className: String, rarity: String, set: String, type: String, cost: String)>()

// Opening a file inside the documentation directory
if let dir = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first {

    let fileURL = dir.appendingPathComponent(file)

    //reading from the file
    do {
        let allInput = try String(contentsOf: fileURL, encoding: .utf8)
        let tempArrayAllLines = allInput.components(separatedBy: "\r\n")

        // Spliting separed lines with "\t" and add it to the tuple list
        var i: Int = 0
        while i < (tempArrayAllLines.count-1) {
            let elementsInLine = tempArrayAllLines[i].components(separatedBy: "\t")
            cards.append((name: elementsInLine[0], className: elementsInLine[1], rarity: elementsInLine[2], set: elementsInLine[3], type: elementsInLine[4], cost: elementsInLine[5]))
            i += 1;
        }
    }
    catch {
        print("You gotta put file named <\(file)> on this directory -> <\(dir)>")
        print(error)
    }
}


func mergeSortFull(_ array: [(name: String, className: String, rarity: String, set: String, type: String, cost: String)]) -> [(name: String, className: String, rarity: String, set: String, type: String, cost: String)]{
    // Breaking the recursive output
    if array.count <= 1 {
        return array
    }

    // Dividing array into parts
    let mid = array.count/2
    var part_a = mergeSortFull(Array(array[0..<mid]))
    var part_b = mergeSortFull(Array(array[mid..<array.count]))

    // Merging parts that we broke
    var array = Array<(name: String, className: String, rarity: String, set: String, type: String, cost: String)>()
    var offset_a = 0
    var offset_b = 0
    while offset_a < part_a.count && offset_b < part_b.count{
        let a = part_a[offset_a]
        let b = part_b[offset_b]

        if a.className < b.className{
            array.append(a)
            offset_a += 1
        }else if a.className == b.className {
            if Int(a.cost)! < Int(b.cost)! {
                array.append(a)
                offset_a += 1
            }else if Int(a.cost) == Int(b.cost){
                if a.name <= b.name {
                    array.append(a)
                    offset_a += 1
                }else {
                    array.append(b)
                    offset_b += 1
                }
            }else {
                array.append(b)
                offset_b += 1
            }
        }else {
            array.append(b)
            offset_b += 1
        }
    }

    while offset_a < part_a.count {
        array.append(part_a[offset_a])
        offset_a += 1
    }
    while offset_b < part_b.count {
        array.append(part_b[offset_b])
        offset_b += 1
    }

    return array
}

func mergeSortFilter(_ array: [(name: String, className: String, rarity: String, set: String, type: String, cost: String)]) -> [(name: String, className: String, rarity: String, set: String, type: String, cost: String)]{
    // Breaking the recursive output
    if array.count <= 1 {
        return array
    }

    // Dividing array into parts
    let mid = array.count/2
    var part_a = mergeSortFilter(Array(array[0..<mid]))
    var part_b = mergeSortFilter(Array(array[mid..<array.count]))

    // Merging parts that we broke
    var array = Array<(name: String, className: String, rarity: String, set: String, type: String, cost: String)>()
    var offset_a = 0
    var offset_b = 0
    while offset_a < part_a.count && offset_b < part_b.count{
        let a = part_a[offset_a]
        let b = part_b[offset_b]

        if a.type <= b.type {
            array.append(a)
            offset_a += 1
        }else {
            array.append(b)
            offset_b += 1
        }
    }

    while offset_a < part_a.count {
        array.append(part_a[offset_a])
        offset_a += 1
    }
    while offset_b < part_b.count {
        array.append(part_b[offset_b])
        offset_b += 1
    }

    return array
}

let programStart = Date()

if isFullSort && isMergeSort{
    // Full sort with merge
    sortedArray = mergeSortFull(cards)
}else if !isFullSort && isMergeSort{
    // Filter sort with merge
    sortedArray = mergeSortFilter(cards)
}else if !isFullSort && !isMergeSort{
    // Filter sort with insertion
    var counterOne = 0
    var keyPosition: Int
    var counterTwo: Int

    for key in cards {
        counterTwo = counterOne - 1
        keyPosition = counterOne
        while counterTwo >= 0 {
            // When key is smaller change the key with the other number
            if (cards[counterTwo].type > key.type){
                cards[keyPosition] = cards[counterTwo]
                keyPosition -= 1
            }
            counterTwo -= 1
        }
        cards[keyPosition] = key
        counterOne += 1
    }
    sortedArray = cards
}else{
    // Full sort with insertion
    var counterOne = 0
    var keyPosition: Int
    var counterTwo: Int

    for key in cards {
        counterTwo = counterOne - 1
        keyPosition = counterOne
        while counterTwo >= 0 {
            // When key is smaller change the key with the other number
            if (cards[counterTwo].className > key.className){
                cards[keyPosition] = cards[counterTwo]
                keyPosition -= 1
            }else if (cards[counterTwo].className == key.className) {
                if (Int(cards[counterTwo].cost)! > Int(key.cost)!){
                    cards[keyPosition] = cards[counterTwo]
                    keyPosition -= 1
                }else if (Int(cards[counterTwo].cost)! == Int(key.cost)!) {
                    if (cards[counterTwo].name > key.name){
                        cards[keyPosition] = cards[counterTwo]
                        keyPosition -= 1
                    }
                }
            }
            counterTwo -= 1
        }
        cards[keyPosition] = key
        counterOne += 1
    }
    sortedArray = cards
}
let programFinish = Date()


if let dir = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first {

    let fileURL = dir.appendingPathComponent(outputFileName)

    //writing to the file
    do {
        var i = 0
        var text = ""
        while i < cards.count{
            text += sortedArray[i].name + "\t" + sortedArray[i].className + "\t" + sortedArray[i].rarity + "\t" + sortedArray[i].set + "\t" + sortedArray[i].type + "\t" + sortedArray[i].cost + "\r\n"

            i += 1
        }
        try text.write(to: fileURL, atomically: false, encoding: .utf8)
    }
    catch {
        print(error)
    }
}


let executionTime = programFinish.timeIntervalSince(programStart)
print("Execution time: \(executionTime), is Full sort type: \(isFullSort), is Merge sort: \(isMergeSort)")

