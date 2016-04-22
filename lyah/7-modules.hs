-- Fill in the DistanceConversions module first, and import it here
-- create a higher-order function for converting an area between two dimensions
-- this will take the function for converting a distance, and an area to convert
-- using the functions defined in the DistanceConversions module
-- Example areaConv inchesToCentimetres 9 = 58.0644

module DistanceConversions
( yardsToFeet
, feetToInches
, inchesToCentimetres
) where

-- Define yards to feet
yardsToFeet ::  Float -> Float
yardsToFeet y = y * 3

-- Define feet to inches
feetToInches :: Float -> Float
feetToInches f = f * 12

-- Define inches to centimetres
inchesToCentimetres :: Float -> Float
inchesToCentimetres i = i * 2.54

areaConv :: (Float -> Float) -> Float -> Float
areaConv linearConversion area = (linearConversion area) * (linearConversion 1)

-- define a function for converting square inches into square centimetres
sqInToSqCm :: Float -> Float
sqInToSqCm = (* (2.54^2))

-- define a function for converting square chains (22 yards) to square metres
sqChainsToSqM :: Float -> Float
sqChainsToSqM = (* (22^2 * 0.9144^2))
