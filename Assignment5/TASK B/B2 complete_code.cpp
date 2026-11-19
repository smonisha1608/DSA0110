// TODO 1:
double approve(double billed, double cover)
{
    if (billed < 0 || cover < 0)
        throw std::invalid_argument("negative amount");
    if (billed > cover)
        throw ClaimError("exceeds cover");
    return billed;
}

// TODO 2:
double settle(double billed, double cover)
{
    try {
        return approve(billed, cover);
    } catch (const ClaimError& e) {
        std::cout << "audit: " << e.what() << '\n';
        throw;
    }
}
