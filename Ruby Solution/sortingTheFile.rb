
startTime = Time.now
#Defining the constants
isMergeSort = true
isFullSort = false
inputFileName = 'hs-set-10k.txt'
outputFileName = 'hs-set-10k-output.txt'

#Opening the file and creating a struct
Card = Struct.new(:name, :className, :rarity, :set, :type, :cost)
file = File.open(inputFileName, 'r')
data = file.read
eachLineStringArray =  data.split("\r\n")

#creating an array struct and storing all elements
storedCards = []
sortedCards = []
for i in eachLineStringArray
  eachItem = i.split("\t")
  storedCards << Card.new(eachItem[0],eachItem[1],eachItem[2],eachItem[3],eachItem[4],eachItem[5])
end

def mergeSortFull(array)
  # Recursive Output
  if array.size <= 1
    return array
  end

  #Dividing array into parts
  mid = array.size/2
  part_a = mergeSortFull(array[0...mid])
  part_b = mergeSortFull(array[mid..array.size])

  # Merging the array
  array = []
  offset_a = 0
  offset_b = 0

  while offset_a < part_a.size and offset_b < part_b.size
    a = part_a[offset_a]
    b = part_b[offset_b]

    if a.className < b.className
      array << a
      offset_a += 1
    elsif a.className == b.className
      if a.cost.to_i < b.cost.to_i
        array << a
        offset_a += 1
      elsif a.cost.to_i == b.cost.to_i
        if a.name < b.name
          array << a
          offset_a += 1
        else
          array << b
          offset_b += 1
        end
      else
        array << b
        offset_b += 1
      end
    else
      array << b
      offset_b += 1
    end
  end

  while offset_a < part_a.count
    array << part_a[offset_a]
    offset_a += 1
  end
  while offset_b < part_b.count
    array << part_b[offset_b]
    offset_b += 1
  end
  return array
end


def mergeSortFilter(array)
  # Recursive Output
  if array.size <= 1
    return array
  end
  #Dividing array into parts
  mid = array.size/2
  part_a = mergeSortFilter(array[0...mid])
  part_b = mergeSortFilter(array[mid..array.size])

  # Merging the array
  array = []
  offset_a = 0
  offset_b = 0

  while offset_a < part_a.size and offset_b < part_b.size
    a = part_a[offset_a]
    b = part_b[offset_b]

    if a.type <= b.type
      array << a
      offset_a += 1
    else
      array << b
      offset_b += 1
    end
  end

  while offset_a < part_a.count
    array << part_a[offset_a]
    offset_a += 1
  end
  while offset_b < part_b.count
    array << part_b[offset_b]
    offset_b += 1
  end
  return array
end


if (isMergeSort && isFullSort)
    sortedCards = mergeSortFull(storedCards)

elsif (isMergeSort && !isFullSort)
    sortedCards = mergeSortFilter(storedCards)

elsif (!isMergeSort && isFullSort)

  (1...storedCards.size).each { |t|
    counter = t-1
    i = t
    while counter >= 0
      if storedCards[i].className < storedCards[counter].className
        temp = storedCards[counter]
        storedCards[counter] = storedCards[i]
        storedCards[i] = temp
        i -=1
      elsif storedCards[i].className == storedCards[counter].className
        if storedCards[i].cost.to_i < storedCards[counter].cost.to_i
          temp = storedCards[counter]
          storedCards[counter] = storedCards[i]
          storedCards[i] = temp
          i -= 1
        elsif storedCards[i].cost.to_i == storedCards[counter].cost.to_i
          if storedCards[i].name < storedCards[counter].name
            temp = storedCards[counter]
            storedCards[counter] = storedCards[i]
            storedCards[i] = temp
            i -= 1
          end
        end
      end
      counter -= 1
    end
  }
  sortedCards = storedCards

else

  (1...storedCards.size).each { |t|
    counter = t-1
    i = t
    while counter >= 0
      if storedCards[i].type < storedCards[counter].type
        temp = storedCards[counter]
        storedCards[counter] = storedCards[i]
        storedCards[i] = temp
        i -=1
      end
      counter -= 1
    end
  }
  sortedCards = storedCards

end

# write to a file
File.open(outputFileName, 'w') { |file|
  text = ""
  for i in sortedCards
    text += (i.name + "\t" + i.className + "\t" + i.rarity + "\t" + i.set + "\t" +  i.type + "\t" + i.cost + "\r\n")
  end
  file.write(text)
}

endTime = Time.now

puts "Running time is #{(endTime - startTime)} secs"
