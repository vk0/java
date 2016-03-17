

--Реализуйте instance Monoid для типа Xor, в котором mappend выполняет операцию xor.

newtype Xor = Xor { getXor :: Bool }
    deriving (Eq,Show)

instance Monoid Xor where
    mempty = Xor False
    mappend (Xor True) (Xor x) = Xor (not x)
    mappend _ q = q