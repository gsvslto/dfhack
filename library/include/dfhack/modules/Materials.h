/*
https://github.com/peterix/dfhack
Copyright (c) 2009-2011 Petr Mrázek (peterix@gmail.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must
not claim that you wrote the original software. If you use this
software in a product, an acknowledgment in the product documentation
would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

#pragma once
#ifndef CL_MOD_MATERIALS
#define CL_MOD_MATERIALS
/**
 * \defgroup grp_materials Materials module - used for reading raws mostly
 * @ingroup grp_modules
 */
#include "dfhack/Export.h"
#include "dfhack/Module.h"
#include "dfhack/Types.h"
#include "dfhack/BitArray.h"

#include <vector>
#include <string>

namespace DFHack
{
    struct t_syndrome
    {
        // it's lonely here...
    };
    enum material_flags
    {
        MATERIAL_BONE = 0,
        MATERIAL_MEAT,
        MATERIAL_EDIBLE_VERMIN,
        MATERIAL_EDIBLE_RAW,
        MATERIAL_EDIBLE_COOKED,
        MATERIAL_UNK5,
        MATERIAL_ITEMS_METAL,
        MATERIAL_ITEMS_BARRED,
        
        MATERIAL_ITEMS_SCALED = 8,
        MATERIAL_ITEMS_LEATHER,
        MATERIAL_ITEMS_SOFT,
        MATERIAL_ITEMS_HARD,
        MATERIAL_IMPLIES_ANIMAL_KILL,
        MATERIAL_ALCOHOL_PLANT,
        MATERIAL_ALCOHOL_CREATURE,
        MATERIAL_CHEESE_PLANT,
        
        MATERIAL_CHEESE_CREATURE = 16,
        MATERIAL_POWDER_MISC_PLANT,
        MATERIAL_POWDER_MISC_CREATURE,
        MATERIAL_STOCKPILE_GLOB,
        MATERIAL_LIQUID_MISC_PLANT,
        MATERIAL_LIQUID_MISC_CREATURE,
        MATERIAL_LIQUID_MISC_OTHER,
        MATERIAL_WOOD,
        
        MATERIAL_THREAD_PLANT = 24,
        MATERIAL_TOOTH,
        MATERIAL_HORN,
        MATERIAL_PEARL,
        MATERIAL_SHELL,
        MATERIAL_LEATHER,
        MATERIAL_SILK,
        MATERIAL_SOAP,
        
        MATERIAL_ROTS = 32,
        MATERIAL_UNK33,
        MATERIAL_UNK34,
        MATERIAL_UNK35,
        MATERIAL_STRUCTURAL_PLANT_MAT,
        MATERIAL_SEED_MAT,
        MATERIAL_LEAF_MAT,
        MATERIAL_UNK39,
        
        MATERIAL_ENTERS_BLOOD = 40,
        MATERIAL_BLOOD_MAP_DESCRIPTOR,
        MATERIAL_ICHOR_MAP_DESCRIPTOR,
        MATERIAL_GOO_MAP_DESCRIPTOR,
        MATERIAL_SLIME_MAP_DESCRIPTOR,
        MATERIAL_PUS_MAP_DESCRIPTOR,
        MATERIAL_GENERATES_MIASMA,
        MATERIAL_IS_METAL,
        
        MATERIAL_IS_GEM = 48,
        MATERIAL_IS_GLASS,
        MATERIAL_CRYSTAL_GLASSABLE,
        MATERIAL_ITEMS_WEAPON,
        MATERIAL_ITEMS_WEAPON_RANGED,
        MATERIAL_ITEMS_ANVIL,
        MATERIAL_ITEMS_AMMO,
        MATERIAL_ITEMS_DIGGER,
        
        MATERIAL_ITEMS_ARMOR = 56,
        MATERIAL_ITEMS_DELICATE,
        MATERIAL_ITEMS_SIEGE_ENGINE,
        MATERIAL_ITEMS_QUERN,
        MATERIAL_IS_STONE,
        MATERIAL_UNDIGGABLE,
        MATERIAL_YARN,
        MATERIAL_STOCKPILE_GLOB_PASTE,
        
        MATERIAL_STOCKPILE_GLOB_PRESSED = 64,
        MATERIAL_DISPLAY_UNGLAZED,
        MATERIAL_DO_NOT_CLEAN_GLOB,
        MATERIAL_NO_STONE_STOCKPILE,
        MATERIAL_STOCKPILE_THREAD_METAL,
        MATERIAL_UNK69,
        MATERIAL_UNK70,
        MATERIAL_UNK71,
        
        MATERIAL_UNK72 = 72,
        MATERIAL_UNK73,
        MATERIAL_UNK74,
        MATERIAL_UNK75,
        MATERIAL_UNK76,
        MATERIAL_UNK77,
        MATERIAL_UNK78,
        MATERIAL_UNK79,
    };
    enum inorganic_flags
    {
        INORGANIC_LAVA = 0,
        INORGANIC_UNK1,
        INORGANIC_UNK2,
        INORGANIC_SEDIMENTARY,
        INORGANIC_SEDIMENTARY_OCEAN_SHALLOW,
        INORGANIC_IGNEOUS_INTRUSIVE,
        INORGANIC_IGNEOUS_EXTRUSIVE,
        INORGANIC_METAMORPHIC,

        INORGANIC_DEEP_SURFACE = 8,
        INORGANIC_METAL_ORE, // maybe
        INORGANIC_AQUIFER,
        INORGANIC_SOIL,
        INORGANIC_SOIL_OCEAN,
        INORGANIC_SOIL_SAND,
        INORGANIC_SEDIMENTARY_OCEAN_DEEP,
        INORGANIC_THREAD_METAL, // maybe

        INORGANIC_DEEP = 16, // in general
        INORGANIC_SOIL2, // more soil?
        INORGANIC_DEEP_SPECIAL,
        INORGANIC_UNK19,
        INORGANIC_UNK20,
        INORGANIC_UNK21,
        INORGANIC_UNK22,
        INORGANIC_UNK23,

        INORGANIC_UNK24 = 24,
        INORGANIC_WAFERS,
        INORGANIC_UNK26,
        INORGANIC_UNK27,
        INORGANIC_UNK28,
        INORGANIC_UNK29,
        INORGANIC_UNK30,
        INORGANIC_UNK31,
    };
    //Environment locations:
    enum environment_location
    {
        ENV_SOIL,
        ENV_SOIL_OCEAN,
        ENV_SOIL_SAND,
        ENV_METAMORPHIC,
        ENV_SEDIMENTARY,
        ENV_IGNEOUS_INTRUSIVE,
        ENV_IGNEOUS_EXTRUSIVE,
        ENV_ALLUVIAL,
    };
    //Inclusion types:
    enum inclusion_type
    {
        INCLUSION_NONE, // maybe
        INCLUSION_VEIN,
        INCLUSION_CLUSTER,
        INCLUSION_CLUSTER_SMALL,
        INCLUSION_CLUSTER_ONE,
    };
    /// Research by Quietust
    struct df_material
    {
        std::string Material_ID;
        std::string IS_GEM_singular;
        std::string IS_GEM_plural;
        std::string STONE_NAME;
        int16_t SPEC_HEAT;
        int16_t HEATDAM_POINT;
        int16_t COLDDAM_POINT;
        int16_t IGNITE_POINT;
        int16_t MELTING_POINT;
        int16_t BOILING_POINT;
        int16_t MAT_FIXED_TEMP;
        //int16_t padding; // added by compiler automatically
        int32_t SOLID_DENSITY;
        int32_t LIQUID_DENSITY;
        int32_t MOLAR_MASS;
        int32_t STATE_COLOR_SOLID;  // (color token index)
        int32_t STATE_COLOR_LIQUID; // (color token index)
        int32_t STATE_COLOR_GAS;    // (color token index)
        int32_t STATE_COLOR_POWDER; // (color token index)
        int32_t STATE_COLOR_PASTE;  // (color token index)
        int32_t STATE_COLOR_PRESSED;// (color token index)
        std::string STATE_NAME_SOLID;
        std::string STATE_NAME_LIQUID;
        std::string STATE_NAME_GAS;
        std::string STATE_NAME_POWDER;
        std::string STATE_NAME_PASTE;
        std::string STATE_NAME_PRESSED;
        std::string STATE_ADJ_SOLID;
        std::string STATE_ADJ_LIQUID;
        std::string STATE_ADJ_GAS;
        std::string STATE_ADJ_POWDER;
        std::string STATE_ADJ_PASTE;
        std::string STATE_ADJ_PRESSED;
        int32_t ABSORPTION;
        int32_t BENDING_YIELD;
        int32_t SHEAR_YIELD;
        int32_t TORSION_YIELD;
        int32_t IMPACT_YIELD;
        int32_t TENSILE_YIELD;
        int32_t COMPRESSIVE_YIELD;
        int32_t BENDING_FRACTURE;
        int32_t SHEAR_FRACTURE;
        int32_t TORSION_FRACTURE;
        int32_t IMPACT_FRACTURE;
        int32_t TENSILE_FRACTURE;
        int32_t COMPRESSIVE_FRACTURE;
        int32_t BENDING_STRAIN_AT_YIELD;
        int32_t SHEAR_STRAIN_AT_YIELD;
        int32_t TORSION_STRAIN_AT_YIELD;
        int32_t IMPACT_STRAIN_AT_YIELD;
        int32_t TENSILE_STRAIN_AT_YIELD;
        int32_t COMPRESSIVE_STRAIN_AT_YIELD;
        int32_t MAX_EDGE;
        int32_t MATERIAL_VALUE;
        BitArray <material_flags> mat_flags;
        int16_t EXTRACT_STORAGE;// (item type)
        int16_t BUTCHER_SPECIAL_type;// (item type)
        int16_t BUTCHER_SPECIAL_subtype;// (item subtype)
        //int16_t padding; // added by compiler
        std::string MEAT_NAME_1st_parm; // (adj)
        std::string MEAT_NAME_2nd_parm;
        std::string MEAT_NAME_3rd_parm;
        std::string BLOCK_NAME_1st_parm;
        std::string BLOCK_NAME_2nd_parm;
        std::vector <std::string> MATERIAL_REACTION_PRODUCT_1st_parm;// (e.g. TAN_MAT)
        std::vector <void *>  unknown1;
        std::vector <void *>  unknown2;
        std::vector <std::string> MATERIAL_REACTION_PRODUCT_2nd_parm;// (e.g. LOCAL_CREATURE_MAT)
        std::vector <std::string> MATERIAL_REACTION_PRODUCT_3rd_parm;// (e.g. LEATHER)
        std::vector <std::string> MATERIAL_REACTION_PRODUCT_4th_parm;// (if you used CREATURE_MAT or PLANT_MAT)
        int16_t unknown3;
        //int16_t padding; // added by compiler
        int32_t unknown4;
        std::string HARDENS_WITH_WATER_1st_parm;// (e.g. INORGANIC)
        std::string HARDENS_WITH_WATER_2nd_parm;// (e.g. GYPSUM)
        std::string HARDENS_WITH_WATER_3rd_parm;// (if you used CREATURE_MAT or PLANT_MAT)
        std::vector <std::string> REACTION_CLASS;
        int8_t TILE; // Tile when material is a natural wall
        int16_t BASIC_COLOR_foreground;
        int16_t BASIC_COLOR_bright;
        // what exactly ARE those colors?
        int16_t BUILD_COLOR_foreground;
        int16_t BUILD_COLOR_background;
        int16_t BUILD_COLOR_bright;
        // same...
        int16_t TILE_COLOR_foreground;
        int16_t TILE_COLOR_background;
        int16_t TILE_COLOR_bright;
        int8_t ITEM_SYMBOL; // Tile when material is a dug out stone
        int16_t POWDER_DYE; // (color token index)
        int16_t TEMP_DIET_INFO;// (whatever it means)
        std::vector <t_syndrome *> SYNDROME;
        int32_t SOAP_LEVEL;
        std::string PREFIX;
        // etc...
    };

    /// Research by Quietust
    struct df_inorganic_base
    {
        std::string Inorganic_ID;
        BitArray<inorganic_flags> inorg_flags;
        std::vector <uint32_t> empty1;
        std::vector <int16_t> METAL_ORE_matID; // Vector of indexes of metals produced when ore is smelted
        std::vector <int16_t> METAL_ORE_prob; // Vector of percent chance of each type of metal being produced on smelting
        std::vector <uint32_t> empty2;
        std::vector <int16_t> THREAD_METAL_matID;// Vector of indexes of metals produced when ore undergoes strand extraction
        std::vector <int16_t> THREAD_METAL_prob; // Vector of percent chance of each type of metal being produced on strand extraction
        std::vector <uint32_t> unknown_in_1;
        std::vector <uint32_t> empty3;
        std::vector <int16_t> ENVIRONMENT_SPEC_matID;
        std::vector <int16_t> ENVIRONMENT_SPEC_inclusion_type;
        std::vector <int8_t> ENVIRONMENT_SPEC_prob;
        std::vector <int16_t> ENVIRONMENT_location;
        std::vector <int16_t> ENVIRONMENT_inclusion_type;
        std::vector <int8_t> ENVIRONMENT_prob;
        int32_t unknown_in_2;
    };
    struct df_inorganic_material:public df_inorganic_base, public df_material {};
    /**
     * A copy of the game's material data.
     * \ingroup grp_materials
     */
    class DFHACK_EXPORT t_matgloss
    {
    public:
        std::string id; // raw name
        std::string name; // a sensible human-readable name
        uint8_t fore;
        uint8_t back;
        uint8_t bright;

        int32_t  value;        // Material value
        uint8_t wall_tile;    // Tile when a natural wall
        uint8_t boulder_tile; // Tile when a dug-out stone;
        bool is_gem;

    public:
        t_matgloss();
    };
    /**
     * A copy of the game's inorganic material data.
     * \ingroup grp_materials
     */
    class DFHACK_EXPORT t_matglossInorganic : public t_matgloss
    {
    public:
        // Types of metals the ore will produce when smelted.  Each number
        // is an index into the inorganic matglass vector.
        std::vector<int16_t> ore_types;

        // Percent chance that the ore will produce each type of metal
        // when smelted.
        std::vector<int16_t> ore_chances;

        // Types of metals the ore will produce from strand extraction.
        // Each number is an index into the inorganic matglass vector.
        std::vector<int16_t> strand_types;

        // Percent chance that the ore will produce each type of metal
        // fram strand extraction.
        std::vector<int16_t> strand_chances;

    public:
        //t_matglossInorganic();

        bool isOre();
        bool isGem();
    };

    /**
     * \ingroup grp_materials
     */
    struct t_descriptor_color
    {
        std::string id;
        std::string name;
        float red;
        float green;
        float blue;
    };
    /**
     * \ingroup grp_materials
     */
    struct t_matglossPlant
    {
        std::string id;
        std::string name;
        uint8_t fore;
        uint8_t back;
        uint8_t bright;
        std::string drink_name;
        std::string food_name;
        std::string extract_name;
    };
    /**
     * \ingroup grp_materials
     */
    struct t_bodypart
    {
        std::string id;
        std::string category;
        std::string singular;
        std::string plural;
    };
    /**
     * \ingroup grp_materials
     */
    struct t_colormodifier
    {
        std::string part;
        std::vector<uint32_t> colorlist;
        uint32_t startdate; /* in days */
        uint32_t enddate; /* in days */
    };
    /**
     * \ingroup grp_materials
     */
    struct t_creaturecaste
    {
        std::string id;
        std::string singular;
        std::string plural;
        std::string adjective;
        std::vector<t_colormodifier> ColorModifier;
        std::vector<t_bodypart> bodypart;

        t_attrib strength;
        t_attrib agility;
        t_attrib toughness;
        t_attrib endurance;
        t_attrib recuperation;
        t_attrib disease_resistance;
        t_attrib analytical_ability;
        t_attrib focus;
        t_attrib willpower;
        t_attrib creativity;
        t_attrib intuition;
        t_attrib patience;
        t_attrib memory;
        t_attrib linguistic_ability;
        t_attrib spatial_sense;
        t_attrib musicality;
        t_attrib kinesthetic_sense;
    };
    #define NUM_CREAT_ATTRIBS 17

    /**
     * \ingroup grp_materials
     */
    struct t_matglossOther
    {
        std::string id;
    };
    /**
     * \ingroup grp_materials
     */
    struct t_creatureextract
    {
        std::string id;
    };
    /**
     * \ingroup grp_materials
     */
    struct t_creaturetype
    {
        std::string id;
        std::vector <t_creaturecaste> castes;
        std::vector <t_creatureextract> extract;
        uint8_t tile_character;
        struct
        {
            uint16_t fore;
            uint16_t back;
            uint16_t bright;
        } tilecolor;
    };

    /**
     * this structure describes what are things made of in the DF world
     * \ingroup grp_materials
     */
    struct t_material
    {
        int16_t itemType;
        int16_t subType;
        int16_t subIndex;
        int32_t index;
        uint32_t flags;
    };
    /**
     * The Materials module
     * \ingroup grp_modules
     * \ingroup grp_materials
     */
    class DFHACK_EXPORT Materials : public Module
    {
    public:
        Materials();
        ~Materials();
        bool Finish();

        std::vector<df_inorganic_material*>* df_inorganic;
        std::vector<t_matglossInorganic> inorganic;
        std::vector<t_matgloss> organic;
        std::vector<t_matgloss> tree;
        std::vector<t_matgloss> plant;
        std::vector<t_matgloss> race;
        std::vector<t_creaturetype> raceEx;
        std::vector<t_descriptor_color> color;
        std::vector<t_matglossOther> other;
        std::vector<t_matgloss> alldesc;

        bool ReadInorganicMaterials (void);
        bool ReadOrganicMaterials (void);
        bool ReadWoodMaterials (void);
        bool ReadPlantMaterials (void);
        bool ReadCreatureTypes (void);
        bool ReadCreatureTypesEx (void);
        bool ReadDescriptorColors(void);
        bool ReadOthers (void);

        bool ReadAllMaterials(void);

        std::string getType(const t_material & mat);
        std::string getDescription(const t_material & mat);
    private:
        class Private;
        Private* d;
    };
}
#endif

